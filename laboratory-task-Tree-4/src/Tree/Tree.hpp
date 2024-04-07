#ifndef TREE_HPP
#define TREE_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream> 
#include <sstream> 
#include <stdexcept> 

enum TreeType { DECIDUOUS, CONIFEROUS };

class Tree {
protected:
    std::string name;
    size_t age;
    TreeType type;

public:
    // Конструктор с параметрами
    Tree(const std::string&, size_t, TreeType);

    // Деструктор
    virtual ~Tree() {}

    // Вывод информации
    virtual void printInfo() const = 0;

    // Получение имени
    const std::string& getName() const;

    // Получение возраста
    size_t getAge() const;

    // Получение типа дерева
    TreeType getType() const;
};

#endif 

