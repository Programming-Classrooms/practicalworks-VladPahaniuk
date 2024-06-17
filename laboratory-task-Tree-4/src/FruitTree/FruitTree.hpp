#ifndef FRUITTREE_HPP
#define FRUITTREE_HPP

#include "src/Tree/Tree.hpp"

class FruitTree : public Tree {
private:
    double harvestWeight;
    size_t storageDuration;

public:
    // Конструктор с параметрами
    FruitTree(const std::string&, size_t, TreeType, double, size_t);

    // Вывод информации
    void printInfo() const override;

    // Получение массы урожая
    double getHarvestWeight() const;

    // Получение строка хранения
    size_t getStorageDuration() const;

    // Деструктор
    ~FruitTree();
};


#endif