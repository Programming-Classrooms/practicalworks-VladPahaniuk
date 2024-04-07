#ifndef TREECONTAINER_HPP
#define TREECONTAINER_HPP

#include "src/Tree/Tree.hpp"
#include "src/ForestTree/ForestTree.hpp"
#include "src/FruitTree/FruitTree.hpp"

class TreeContainer {
private:
    std::vector<Tree*> trees;
public:
    // Добавление элемента в контейнер
    void addTree(Tree*);

    // Вывод информации
    void printAllTreesInfo() const;

    // Подсчет деревьев по типу
    size_t countTreesByType(TreeType) const;

    // Подсчет деревьев по разновидности
    size_t countTreesByKind(const std::string&) const;

    // Сортировка по имении и возрасту
    void sortTreesByNameAndAge();

    // Чтение деревьев из файла
    void loadTreesFromFile(const std::string &);
    
   // Деструктор
   ~TreeContainer(); 
};


#endif
