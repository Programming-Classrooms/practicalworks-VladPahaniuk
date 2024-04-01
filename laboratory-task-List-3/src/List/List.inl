#include "List.hpp"

// Конструкторр с параметрами для Node(узла)
template <typename Type>
List<Type>::Node::Node(Type data, Node* pointerNextElement) : data(data), pointerNextElement(pointerNextElement)
{}

// Конструктор по умолчанию
template<typename Type>
List<Type>::List() : size(0), head(nullptr) {}

// Конструктор копирования
template<typename Type>
List<Type>::List(const List<Type>& other) : size(0), head(nullptr) {
  Node* current = other.head;
  while (current) {
    push_back(current->data);
    current = current->pointerNextElement;
  }
}

// Деструктор
template<typename Type>
List<Type>::~List() {
  clear();
}

// Оператор присваивания
template<typename Type>
List<Type>& List<Type>::operator=(const List<Type>& other) {
  if (this != &other) { 
    clear();
    Node* current = other.head;
    while (current) {
      push_back(current->data);
      current = current->pointerNextElement;
    }
  }
  return *this;
}

// Получение количества элементов List
template<typename Type>
size_t List<Type>::getSize() const
{
  return size;
}

// push_front
template<typename Type>
void List<Type>::push_front(Type data)
{
  head = new Node(data, head);
  size++;

}

// push_back
template<typename Type>
void List<Type>::push_back(Type data) {
  if (this->head == nullptr) {
    this->head = new Node(data);
  }
  else {
    Node* current = this->head;
    while (current->pointerNextElement != nullptr) {
      current = current->pointerNextElement;
    }
    current->pointerNextElement = new Node(data);
  }
  size++;
}

// pop_front
template<typename Type>
void List<Type>::pop_front()
{
  Node* temp = head;
  head = head->pointerNextElement;
  delete temp;
  size--;
}

// pop_back
template<typename Type>
void List<Type>::pop_back()
{
  if (!head) {
    throw std::out_of_range("List is empty");
  }
  if (size == 1) {
    pop_front();
  }
  else {
    Node* current = head;
    Node* previous = nullptr;
    while (current->pointerNextElement) {
      previous = current;
      current = current->pointerNextElement;
    }
    delete current;
    if (previous) {
      previous->pointerNextElement = nullptr;
    }
    else {
      head = nullptr;
    }
    size--;
  }
}

// Удаление элемента по значению 
template<typename Type>
void List<Type>::removeByValue(const Type& value) {
  Node* current = head;
  Node* previous = nullptr;

  while (current != nullptr) {
    if (current->data == value) {
      if (previous == nullptr) {
        head = current->pointerNextElement;
      }
      else {
        previous->pointerNextElement = current->pointerNextElement;
      }
      delete current;
      size--;
      return; 
    }
    previous = current;
    current = current->pointerNextElement;
  }
}

// Поиск элемента по значению
template<typename Type>
size_t List<Type>::searchWithValue(const Type& value)
{
  size_t count = 0;
  Node* current = head;

  while (current != nullptr) {
    if (current->data == value) {
      count++;
    }

    current = current->pointerNextElement;
  }

  return count;
}

// Вывод через сallback функцию
template<typename Type>
void List<Type>::forEach(void (*callback)(const Type&)) {
  Node* current = head;

  while (current != nullptr) {
    callback(current->data); // Вызываем callback-функцию для текущего элемента
    current = current->pointerNextElement;
  }
}

// operator[]
template<typename Type>
Type& List<Type>::operator[](const size_t index)
{
  if (index >= size || !head) {
    throw std::out_of_range("Index out of range or list is empty");
  }
  size_t counter = 0;
  Node* current = this->head;
  while (current != nullptr)
  {
    if (counter == index)
    {
      return current->data;
    }
    current = current->pointerNextElement;
    counter++;

  }
}

// Очищение List
template<typename Type>
void List<Type>::clear()
{
  while (size)
  {
    pop_front();
  }
}
