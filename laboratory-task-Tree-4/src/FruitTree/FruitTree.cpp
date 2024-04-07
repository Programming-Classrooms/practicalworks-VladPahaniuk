#include "FruitTree.hpp"

// Конструктор с параметрами
FruitTree::FruitTree(const std::string& name, size_t age, TreeType type, double harvestWeight, size_t storageDuration)
    : Tree(name, age, type), harvestWeight(harvestWeight), storageDuration(storageDuration) {}

// Вывод информации
void FruitTree::printInfo() const {
    std::cout << "Fruit Tree\nName: " << getName() << "\nAge: " << getAge() << "\nType: ";
    if (getType() == DECIDUOUS) {
        std::cout << "Deciduous";
    }
    else {
        std::cout << "Coniferous";
    }
    std::cout << "\nHarvest Weight: " << harvestWeight << " kg\nStorage Duration: " << storageDuration << " days\n\n";
}

// Получение массы урожая
double FruitTree::getHarvestWeight() const {
    return harvestWeight;
}

// Получение строка хранения
size_t FruitTree::getStorageDuration() const {
    return storageDuration;
}

// Деструктор
FruitTree::~FruitTree()
{}
