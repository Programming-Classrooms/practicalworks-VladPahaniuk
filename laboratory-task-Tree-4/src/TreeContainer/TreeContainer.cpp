#include "TreeContainer.hpp"

// Добавление элемента в контейнер
void TreeContainer::addTree(Tree* tree) {
    trees.push_back(tree);
}

// Вывод информации
void TreeContainer::printAllTreesInfo() const {
     for (const Tree* tree : trees) {
        tree->printInfo();
    }
}

// Подсчет деревьев по типу
size_t TreeContainer::countTreesByType(TreeType type) const {
    size_t count = 0;
    for (const Tree* tree : trees) {
        if (tree->getType() == type) {
            count++;
        }
    }
    return count;
}

// Подсчет деревьев по разновидности
size_t TreeContainer::countTreesByKind(const std::string& kind) const {
    size_t count = 0;
    for (const auto& tree : trees) {
        if (kind == "Forest" && dynamic_cast<ForestTree*>(tree) != nullptr) {
            count++;
        } else if (kind == "Fruit" && dynamic_cast<FruitTree*>(tree) != nullptr) {
            count++;
        }
    }
    return count;
}

// Сортировка по имении и возрасту
void TreeContainer::sortTreesByNameAndAge() {
    std::sort(trees.begin(), trees.end(), [](Tree* a, Tree* b) {// лямбда-функция
        if (a->getName() == b->getName()) {
            return a->getAge() > b->getAge();
        }
        return a->getName() < b->getName();
    });
}

// Чтение деревьев из файла
void TreeContainer::loadTreesFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string treeType;
        iss >> treeType;

        if (treeType == "Forest") {
            std::string name;
            size_t age, quantityOfWood;
            iss >> name >> age >> quantityOfWood;
            trees.push_back(new ForestTree(name, age, TreeType::CONIFEROUS, quantityOfWood));
        }
        else if (treeType == "Fruit") {
            std::string name;
            size_t age;
            double harvestWeight;
            size_t storageDuration;
            iss >> name >> age >> harvestWeight >> storageDuration;
            trees.push_back(new FruitTree(name, age, TreeType::DECIDUOUS, harvestWeight, storageDuration));
        }
        else
        {
            throw std::runtime_error("Unknown tree type in file");
        }
    }
    file.close(); 
}

// Деструктор
TreeContainer::~TreeContainer() {
    for (Tree* tree : trees) {
        delete tree;
    }
}
