
#ifndef THREE_HPP
#define THREE_HPP

#include<iostream>
#include<string>

struct Book {

    std::string cipher; 
    std::string title;  
    std::string author;

    //Констукор по умолчанию
    Book() : cipher(""), title(""), author("") {}

    // Конструктор с параметрами
    Book(const std::string& cipher, const std::string& title, const std::string& author) :
        cipher(cipher), title(title), author(author) {}

    // Определение оператора < для сравнения книг по шифру
    bool operator<(const Book& other) const {
        return cipher < other.cipher;
    }

    // Оператор равенства 
    bool operator==(const Book& rhs) {
    return cipher == rhs.cipher;
    }

    // Оператор больше 
    bool operator>(const Book& rhs) {
    return cipher > rhs.cipher;
    }

    // Вывод в поток
    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "Cipher: " << book.cipher << ", Title: " << book.title << ", Author: " << book.author;
    return os;
}

};

template<typename T>
struct Node {

    Node(Node* = nullptr, Node* = nullptr, Node* = nullptr);

    T value;
    // Указател  на правого потомка 
    Node<T>* right;
    // Указатель на левого потомка
    Node<T>* left;
    // Указатель на родителя[у корня всего дерева он nullptr]
    Node<T>* parent;
};


template<typename T>
class Tree
{
private:
    Node<T>* root;

    /*============== Обходы дерева ==============*/

    // Прямой обход
    void directBypass(std::ostream&, Node<T>*);

    // Центральный обход
    void centralBypass(void (Node<T>*), Node<T>*);

    // Обратный обход
    void reverseBypass(void (Node<T>*), Node<T>*);

    // Поиск
    Node<T>* find(T, Node<T>*);

    // Вставка
    Node<T>* insert(T, Node<T>*);

    // Функция копирования узла
    Node<T>* copyNodes(Node<T>*);

    // Функция поиска узла по шифру
     Node<T>* find(const std::string& cipher, Node<T>* node);

public:

/*================ Конструктоы ==============*/

// По умолчанию
    Tree();

// Копировнаия
    Tree(const Tree&);

// Деструктор 
    ~Tree();


/*============== Методы ==============*/

    // Удаление эллемента
    bool deleteItem(T);

    // Поиск
    bool find(T);
    
    // Обёртка для вставки
    bool insert(T);


/*============= Операторы =============*/

// Оператр присваивания
Tree& operator=(const Tree&);

// Оператор []
T& operator[](const std::string&);

// Вывод
void print();

};

#include"Tree.inl";

#endif //FUNCS_HPP
