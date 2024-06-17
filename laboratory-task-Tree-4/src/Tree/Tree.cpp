#include "Tree.hpp"

// Конструктор с параметрами
Tree::Tree(const std::string& name, size_t age, TreeType type)
    : name(name), age(age), type(type) {}

// Получение имени
const std::string& Tree::getName() const {
    return name;
}

// Получение возраста
size_t Tree::getAge() const {
    return age;
}

// Получение типа дерева
TreeType Tree::getType() const {
    return type;
}

