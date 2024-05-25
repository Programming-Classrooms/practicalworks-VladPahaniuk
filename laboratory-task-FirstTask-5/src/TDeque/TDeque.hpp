#ifndef TDEQUE_HPP
#define TDEQUE_HPP

#include <iostream>
#include <exception>
#include <string>

template <class TInfo>
class TDeque /* дек – двустороння очередь */
{
    
protected:
template <class TInfo_struct>

    struct TDequeItem // элемент дека
    {
    TInfo data; // данные
    TDequeItem<TInfo_struct>* next; // указатель на следующий элемент
    TDequeItem<TInfo_struct>* prev; // указатель на предыдущий элемент
    };

  /* указатели на первый и последний элементы в сп  иске */
  TDequeItem<TInfo>* begin, * end;
  int size; // количество элементов в деке

  void DeleteItem(TDequeItem<TInfo>*); // удаление элемента по указателю
  bool CorrectIndex(unsigned index) const; // корректность указателя
  TDequeItem<TInfo>* PtrByIndex(unsigned) const; // указатель на элемент с заданным индексом
   void Erase(); // удаление всех элементов

public:

  TDeque(); // конструктор
  TDeque(const TDeque& obj); // конструктор копирования
  virtual ~TDeque(); // деструктор

  void InsFront(TInfo data); // включить элемент в голову дека
  void InsRear(TInfo data); // включить элемент в хвост дека
  void DelFront(); // исключить элемент из головы дека
  void DelRear(); // исключить элемент из хвоста дека

  const TInfo& GetByIndex(unsigned) const; // получить элемент по индексу

  void SetByIndex(TInfo, unsigned); // изменить элемент по индексу

  void Browse(void WorkItem(TInfo&)); // просмотр с изменением элементов
  void Browse(void WorkItem(TInfo)) const; // просмотр без изменения элементов
  
  void Print() const; // вывод дека
  void Clone(const TDeque&); // копирование объекта
  
  const TDeque<TInfo>& operator = (const TDeque<TInfo>&);// оператор присваивания
};

#include"TDeque.inl"

#endif
