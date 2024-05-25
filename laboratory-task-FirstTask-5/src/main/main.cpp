#include "src/TDeque/TDeque.hpp"

#include <iostream>

void WorkItem(int& data) {
    data *= data; 
}

void WorkItemPrint(int data) {
    std::cout << data << " ";
}

int main() {
    try
    {
    
    // Создание дека целых чисел
    TDeque<int> intDeque;

    // Вставка элементов в начало и конец
    intDeque.InsFront(5);
    intDeque.InsFront(3);
    intDeque.InsRear(7);
    intDeque.InsRear(9);

    // Вывод дека без изменения элементов
    std::cout << "Дек целых чисел (без изменения):\n";
    intDeque.Browse(WorkItemPrint);

    // Применение функции к каждому элементу с изменением
    std::cout << "\n\nДек целых чисел (возврат квадратов):\n";
    intDeque.Browse(WorkItem);

    // Вывод дека после изменения элементов
    std::cout << "\nДек целых чисел (квадраты):\n";
    intDeque.Print();

    // Удаление элемента с начала дека
    std::cout << "\nУдаление элемента с начала дека:\n";
    intDeque.DelFront();
    intDeque.Print();

    // Удаление элемента с конца дека
    std::cout << "\nУдаление элемента с конца дека:\n";
    intDeque.DelRear();
    intDeque.Print();

    // Создание дека указателей на символы
    TDeque<const char*> charPtrDeque;

    // Вставка элементов в начало и конец
    charPtrDeque.InsFront("Hello");
    charPtrDeque.InsFront("World");
    charPtrDeque.InsRear("!");

    // Вывод дека указателей на символы
    std::cout << "\nДек указателей на символы:\n";
    charPtrDeque.Print();

    // Создание копии дека указателей на сивол
    TDeque<const char*> charPtrDequeCopy;
    charPtrDequeCopy.Clone(charPtrDeque);

    // Вывод копии дека указателей на сивол
    std::cout << "\nКопия дека символов:\n";
    charPtrDequeCopy.Print();

    // Установка нового значения элемента в копии дека
    charPtrDequeCopy.SetByIndex("*", 2);

    // Вывод копии дека после изменения элемента
    std::cout << "\nКопия дека указателей на сивол после изменения элемента:\n";
    charPtrDequeCopy.Print();

    // Создание копии дека целых чисел
    TDeque<int> intDequeCopy;
    intDequeCopy.Clone(intDeque);

    // Вывод копии дека целых чисел
    std::cout << "\nКопия дека целых чисел:\n";
    intDequeCopy.Print();

    // Установка нового значения элемента в копии дека
    intDequeCopy.SetByIndex(100, 1);

    // Вывод копии дека после изменения элемента
    std::cout << "\nКопия дека целых чисел после изменения элемента:\n";
    intDequeCopy.Print();

    // Получение элемента из оригинального дека
    std::cout << "\nЭлемент с индексом 1 в оригинальном деке: " << intDeque.GetByIndex(1) << std::endl;

    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::out_of_range e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}