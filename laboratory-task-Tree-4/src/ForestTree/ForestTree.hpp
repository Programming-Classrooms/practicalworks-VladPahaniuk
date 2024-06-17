#ifndef FORESTTREE_HPP
#define FORESTTREE_HPP
#include "src/Tree/Tree.hpp"

class ForestTree : public Tree {
private:
    size_t quantityOfWood;
public:
    // Конструктор с параметрами
    ForestTree(const std::string&, size_t, TreeType, size_t);

    // Вывод информации
    void printInfo() const override;

    // Получение количества древесины
    size_t getQuantityOfWood() const;

    // Деструктор
     ~ForestTree(); 
};

#endif
