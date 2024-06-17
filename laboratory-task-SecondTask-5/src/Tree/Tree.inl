
#include "Tree.hpp"

/*======================================*/
/*=========== Конструкторы =============*/
/*======================================*/

// Конструктор с параметрами
template<typename T>
Node<T>::Node(Node* parentSource, Node* leftSource, Node* rightSource) : 
                            parent(parentSource),
                            left(leftSource),
                            right(rightSource)
{}

// Конструктор по умолчанию
template<typename T>
Tree<T>::Tree()
{
    this->root = nullptr;
}

// Конструктор копирования
template<typename T>
Tree<T>::Tree(const Tree& other) {
    root = copyNodes(other.root);
}

// Деструктор
template<typename T>
Tree<T>::~Tree()
{
    this->reverseBypass([](Node<T>* node) {delete node;}, this->root);
}


/*======================================*/
/*============== Методы ================*/
/*======================================*/

// Копирование элемента
template<typename T>
Node<T>* Tree<T>::copyNodes(Node<T>* node) {
    if (node == nullptr) {
        return nullptr;
    }

    Node<T>* newNode = new Node<T>;
    newNode->value = node->value;
    newNode->left = copyNodes(node->left);
    if (newNode->left != nullptr) { 
        newNode->left->parent = newNode;
    }
    newNode->right = copyNodes(node->right);
    if (newNode->right != nullptr) {
        newNode->right->parent = newNode;
    }

    return newNode;
}

// Функция поиска узла по шифру
template <typename T>
Node<T>* Tree<T>::find(const std::string &cipher, Node<T> *node)
{
     if (node == nullptr) {
        return nullptr;
    }
    if (node->value.cipher == cipher) {
        return node;
    }
    if (cipher < node->value.cipher) {
        return find(cipher, node->left);
    } else {
        return find(cipher, node->right);
    }
}


// Перегрузка оператора присваивания
template<typename T>
Tree<T>& Tree<T>::operator=(const Tree& other) {
    if (this == &other) {
        return *this;
    }

    this->~Tree();

    root = copyNodes(other.root);

    return *this;
}


// Поиск эллемента[внутреня функия]
template<typename T>
Node<T>* Tree<T>::find(T value, Node<T>* node)
{   
    if (node == nullptr) {
        return nullptr;
    }
    if (node->value == value) {
        return node;
    }
    if (node->value > value) {
        return find(value, node->left);
    }
    if (node->value < value) {
        return find(value, node->right);
    }    
}

// Поиск эллемента[пользовательская функция]
template<typename T>
bool Tree<T>::find(T value)
{   
    return this->find(value, this->root) != nullptr;
}

// Обёртка для вставки
template<typename T>
bool Tree<T>::insert(T value)
{
    return this->insert(value, this->root) == nullptr;
}

// Вставка
template<typename T>
Node<T>* Tree<T>::insert(T value, Node<T>* node)
{

    if(root == nullptr) {
        root = new Node<T>;
        root->value = value;
        return root;
    }
    
    if (node->value < value) {
        if (node->right == nullptr){
            node->right = new Node<T>(node);
            node->right->value = value;
            return node->right;
        }
        else if (node->right->value == value) {
            return node->right;
        }
        else {
            return insert(value, node->right);
        }
    }

    if (node->value > value) {
        if (node->left == nullptr){
            node->left = new Node<T>(node);
            node->left->value = value;
            return node->left;
        } 
        else if (node->left->value == value) {
            return node->left;
        }
        else {
            return insert(value, node->left);
        }
    }
}

// Удаление элемента
template<typename T>
bool Tree<T>::deleteItem(T value)
{
    Node<T>* node = this->find(value, this->root);

    if (node == nullptr) {
        return false;
    }

    if (node->right == nullptr) {
        if(node->parent->value < node->value) {
            node->parent->right = node->left;
        }
        else {
            node->parent->left = node->left;      
        }
        delete node;
        return true;
    }

    if (node->left == nullptr) {
        if(node->parent->value < node->value) {
            node->parent->right = node->right;
        }
        else {
            node->parent->left = node->right;
        }
        delete node;
        return true;
    }

    Node<T>* maxEll = node->left;
    while (maxEll->right != nullptr) {
        maxEll = maxEll->right;
    }

    maxEll->parent->right = maxEll->left;

    maxEll->right = node->right;
    maxEll->left = node->left;

    maxEll->parent = node->parent;
    delete node;
    return true;
}

// Центральный обход
template<typename T>
void Tree<T>::centralBypass(void func(Node<T>*), Node<T>* node)
{
    if (node->right == nullptr && node->left == nullptr) {
        func(node);
        return;
    }

    if(node->left != nullptr) {
        centralBypass(func, node->left);
    }
    
    func(node);

    if(node->right != nullptr) {
        centralBypass(func, node->right);
    }
    return;
}

// Обратный обход
template<typename T>
 void Tree<T>::reverseBypass(void func(Node<T>*), Node<T>* node)
 {
    if (node->right == nullptr && node->left == nullptr) {
        func(node);
        return;
    }

    if (node->left != nullptr) {
        reverseBypass(func, node->left);
    }

    if (node->right != nullptr) {
        reverseBypass(func, node->right);
    }

    func(node);
    return;
}

// Оператор []
template<typename T>
T& Tree<T>::operator[](const std::string& cipher) {
    Node<T>* result = find(cipher, root);
    if (result == nullptr) {
        throw std::out_of_range("No node found at the given cipher");
    }
    return result->value;
}


// Прямой обход
template<typename T>
void Tree<T>::directBypass(std::ostream& out, Node<T>* node)
{
    if(!node){
        return;
    }
    out << node->value << ' ';
    directBypass(out, node->left);
    directBypass(out, node->right);
}

// Вывод дерева
template<typename T>
void Tree<T>::print() {
    this->centralBypass([](Node<T>* node) {std::cout << node->value << '\n';}, this->root);
}
