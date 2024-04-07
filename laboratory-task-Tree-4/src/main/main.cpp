#include "src/TreeContainer/TreeContainer.hpp"
#include "src/ForestTree/ForestTree.hpp"
#include "src/FruitTree/FruitTree.hpp"
#include "src/Tree/Tree.hpp"

bool checkFile(std::ifstream &file, std::string path)
{
    if (!file.good())
    {
        throw std::invalid_argument("File not found Path: " + path);
    }

    if (!file)
    {
        throw std::ios_base::failure("Error reading file... Path: " + path);
    }

    if (file.peek() == EOF)
    {
        throw std::runtime_error("File is empty... Path: " + path);
    }

    return true;
}
    
int main()
{
    try
    {
        TreeContainer container;
        std::ifstream file("src/files/trees.txt");
        if (checkFile(file, "src/files/trees.txt"))
        {
            container.loadTreesFromFile("src/files/trees.txt");
            container.printAllTreesInfo();

            std::cout << "/*================================================================================*/" << std::endl;

            std::cout << "\n\nDeciduous Trees Count: " << container.countTreesByType(TreeType::DECIDUOUS) << std::endl;
            std::cout << "Forest Trees Count: " << container.countTreesByKind("Forest") << std::endl << std::endl;

            std::cout << "/*================================================================================*/" << std::endl;

            std::cout << "Sotr Tree by Name and Age" << std::endl;
            container.sortTreesByNameAndAge();
            container.printAllTreesInfo();
        }
    }
    catch (std::invalid_argument &error) {
        std::cerr << "Exception: " << error.what() << std::endl;
    }
    catch (std::ios_base::failure &error) {
        std::cerr << "Exception: " << error.what() << std::endl;
    }
    catch (std::runtime_error &error) {
        std::cerr << "Exception: " << error.what() << std::endl;
    }
    return 0;
}
