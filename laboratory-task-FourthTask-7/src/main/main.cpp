#include "../funcs/funcs.hpp"

int main()
{
    try
    {
        std::set<std::string> fishermanIvan = {"окунь", "щука", "карась"};
        std::set<std::string> fishermanVadim = {"щука", "сом", "краснопёрка"};
        std::set<std::string> fishermanVasy = {"окунь", "карась", "карп"};

        print("Рыбак-Иван: ", fishermanIvan);
        print("Рыбак-Вадим: ", fishermanVadim);
        print("Рыбак-Вася: ", fishermanVasy);

        // Находим рыбаков, которые поймали хотя бы одну рыбу
        std::set<std::string> caughtFishermen = unionFishermen(fishermanIvan, fishermanVadim);
        caughtFishermen = unionFishermen(caughtFishermen, fishermanVasy);
        print("Выловленные рыбы хотя бы одного вида: ", caughtFishermen);

        // Создаем множество всех видов рыб в озере
        std::set<std::string> allFish = {"окунь", "щука", "карась", "сом", "краснопёрка", "плотва"};

        std::set<std::string> notCaughtFish = difference(allFish, caughtFishermen);
        print("Рыбы, которые есть в озере, но не в улове рыбаков: ", notCaughtFish);

        // Записываем данные в файлы
        writeToFile("fishermen.txt", fishermanIvan);
        writeToFile("fishermen.txt", fishermanVadim);
        writeToFile("fishermen.txt", fishermanVasy);
        writeToFile("fishermen.txt", caughtFishermen);
        writeToFile("notCaughtFish.txt", notCaughtFish);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const std::ios_base::failure &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
