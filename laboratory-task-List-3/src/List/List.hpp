#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <exception>

template<typename Type>
class List {
private:
  class Node {
  public:
    Type data;
    Node* pointerNextElement;
    Node(Type = Type(), Node* = nullptr);
  };
  size_t size;
  Node* head;
public:

  // Конструктор по умолчанию
  List();

  // Конструктор копирования
  List(const List<Type>& other);

  // Деструктор
  ~List();

  // Оператор присваивания
  List<Type>& operator=(const List<Type>& other);

  // Получение количества элементов List
  size_t getSize()const;

  // Добавление элемента в начало списка
  void push_front(Type data);

  // Добавление элемента в конец списка
  void push_back(Type data);

  // Удаление элемента вначале списка
  void pop_front();

  // Удаление элемента в конце списка
  void pop_back();

  // Удаление элемента по значению 
  void removeByValue(const Type& value);

  // Поиск элемента по значению
  size_t searchWithValue(const Type& value);

  // Вывод через сallback функцию
  void forEach(void (*callback)(const Type&));

  Type& operator[](const size_t index);
  
  // Очищение List
  void clear();

};

struct Student {
  std::string lastName;
  size_t grades[5];
  size_t studentID;
   bool operator==(const Student& other) const {
        return lastName == other.lastName && studentID == other.studentID;
    }
};


#include "List.inl"
#endif
