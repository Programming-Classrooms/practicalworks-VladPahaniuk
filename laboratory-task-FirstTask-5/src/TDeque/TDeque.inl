#include "TDeque.hpp"
#include <iostream>

/*==========================================================*/
/*====================Конструкторы==========================*/
/*==========================================================*/

// Конструктор по умолчанию
template <class TInfo>
TDeque<TInfo>::TDeque()
{
  begin = end = nullptr;
  size = 0;
}

// Конструктор копирования
template <class TInfo>
TDeque<TInfo>::TDeque(const TDeque &other)
{
  Clone(other);
}

// Деструктор
template <class TInfo>
TDeque<TInfo>::~TDeque()
{
  Erase();
}


/*==========================================================*/
/*=======================Гетеры=============================*/
/*==========================================================*/

// Получение элемента по индексу
template <class TInfo>
const TInfo &TDeque<TInfo>::GetByIndex(unsigned index) const
{
  if (!CorrectIndex(index))
  {
    throw std::invalid_argument("The index is larger than the dimension.");
  }

  TDequeItem<TInfo> *temp = begin;
  for (int i = 0; i < index; ++i)
    temp = temp->next;
  return temp->data;
}


/*==========================================================*/
/*=======================Cетеры=============================*/
/*==========================================================*/

// Установка элемента по индексу
template <class TInfo>
void TDeque<TInfo>::SetByIndex(TInfo data, unsigned index)
{
  if (!CorrectIndex(index))
  {
    throw std::invalid_argument("The index is larger than the dimension.");
  }

  TDequeItem<TInfo> *temp = begin;
  for (int i = 0; i < index; ++i)
    temp = temp->next;
  temp->data = data;
}


/*==========================================================*/
/*=================Бинарные операторы=======================*/
/*==========================================================*/

// Перегрузка оператора присваивания
template <class TInfo>
const TDeque<TInfo> &TDeque<TInfo>::operator=(const TDeque<TInfo> &other)
{
  if (this != &other)
  {
    Clone(other);
  }
  return *this;
}


/*================================================================================*/
/*==================================== Методы ====================================*/
/*================================================================================*/

// Включить элемент в голову дека
template <class TInfo>
void TDeque<TInfo>::InsFront(TInfo data)
{
  TDequeItem<TInfo> *temp = new TDequeItem<TInfo>;
  temp->data = data;
  temp->prev = nullptr;
  temp->next = begin;

  if (size == 0)
    begin = end = temp;
  else
  {
    begin->prev = temp;
    begin = temp;
  }
  size++;
}

// Включить элемент в хвост дека
template <class TInfo>
void TDeque<TInfo>::InsRear(TInfo data)
{
  TDequeItem<TInfo> *temp = new TDequeItem<TInfo>;
  temp->data = data;
  temp->next = nullptr;
  temp->prev = end;

  if (size == 0)
    begin = end = temp;
  else
  {
    end->next = temp;
    end = temp;
  }
  size++;
}

// Исключить элемент из головы дека
template <class TInfo>
void TDeque<TInfo>::DelFront()
{
  if (size == 0)
  {
    std::cout << "The deque is empty.\n";
    return;
  }
  DeleteItem(PtrByIndex(0));
  std::cout << "The first element has been removed\n";
}

// Исключить элемент из хвоста дека
template <class TInfo>
void TDeque<TInfo>::DelRear()
{
  if (size == 0)
  {
    std::cout << "The deque is empty.\n";
    return;
  }
  DeleteItem(PtrByIndex(size - 1));
  std::cout << "The last element has been removed\n";
}

 // Просмотр с изменением элементов
template <class TInfo>
void TDeque<TInfo>::Browse(void WorkItem(TInfo &))
{
  if (size == 0)
    std::cout << "Deque is empty.\n";
  else
  {
    TDequeItem<TInfo> *temp = begin;
    for (int i = 0; i < size; ++i)
    {
      WorkItem(temp->data);
      std::cout << temp->data << " ";
      temp = temp->next;
    }
    std::cout << "\n";
  }
}

// Просмотр без изменения элементов
template <class TInfo>
void TDeque<TInfo>::Browse(void WorkItem(TInfo)) const
{
  if (size == 0)
    std::cout << "Deque is empty.\n";
  else
  {
    TDequeItem<TInfo> *temp = begin;
    for (int i = 0; i < size; ++i)
    {
      WorkItem(temp->data);
      std::cout << temp->data << " ";
      temp = temp->next;
    }
    std::cout << "\n";
  }
}

// Вывод дека
template <class TInfo>
void TDeque<TInfo>::Print() const
{
  if (size == 0)
    std::cout << "Deque is empty.\n";
  else
  {
    TDequeItem<TInfo> *temp = begin;
    while (temp != nullptr)
    {
      std::cout << temp->data << " ";
      temp = temp->next;
    }
    std::cout << "\n";
  }
}

// Удаление всех элементов
template <class TInfo>
void TDeque<TInfo>::Erase() 
{
  int n = size;
  for (int i = 0; i < n; ++i)
    DeleteItem(PtrByIndex(0));
}

// Копирование объекта
template <class TInfo>
void TDeque<TInfo>::Clone(const TDeque &other)
{
  TDeque<TInfo> tempDeque; 

  TDequeItem<TInfo> *temp = other.begin;
  while (temp != nullptr)
  {
    tempDeque.InsRear(temp->data);
    temp = temp->next;
  }
  Erase();
  temp = tempDeque.begin;
  while (temp != nullptr)
  {
    InsRear(temp->data);
    temp = temp->next;
  }
}

// Удаление элемента по указателю
template <class TInfo>
void TDeque<TInfo>::DeleteItem(TDequeItem<TInfo> *other)
{
  if (other == nullptr)
    return;

  if (other->next == nullptr && other->prev == nullptr)
  {
    begin = end = nullptr;
  }
  else if (other->next == nullptr)
  {
    end = other->prev;
    other->prev->next = nullptr;
  }
  else if (other->prev == nullptr)
  {
    begin = other->next;
    other->next->prev = nullptr;
  }
  else
  {
    other->prev->next = other->next;
    other->next->prev = other->prev;
  }

  delete other;
  --size;
}

// указатель на элемент с заданным индексом
template <class TInfo>
TDeque<TInfo>::TDequeItem<TInfo> *TDeque<TInfo>::PtrByIndex(unsigned index) const

{
  if (!CorrectIndex(index))
  {
    throw std::out_of_range("The index is out of range.");
  }

  TDequeItem<TInfo> *t = begin;
  for (unsigned i = 0; i < index; ++i)
  {
    t = t->next;
  }
  return t;
}

// Корректность указателя
template <class TInfo>
bool TDeque<TInfo>::CorrectIndex(unsigned index) const
{
  return index < size && index >= 0;
}
