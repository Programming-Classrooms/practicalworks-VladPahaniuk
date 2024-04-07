#include "ForestTree.hpp"

// Конструктор с параметрами
ForestTree::ForestTree(const std::string& name, size_t age, TreeType type, size_t quantityOfWood)
    : Tree(name, age, type), quantityOfWood(quantityOfWood) {}

// Вывод информации
void ForestTree::printInfo() const {
    std::cout << "Forest Tree\nName: " << getName() << "\nAge: " << getAge() << "\nType: ";
    if (getType() == DECIDUOUS) {
        std::cout << "Deciduous";
    }
    else{
        std::cout << "Coniferous";
    }
    std::cout << "\nQuantity of wood: " << getQuantityOfWood() << " units\n\n";
}

// Получение количества древесины
size_t ForestTree::getQuantityOfWood() const {
    return quantityOfWood;
}

// Деструктор
ForestTree::~ForestTree()
{}
