#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

// Enum class Тип поезда
enum class TrainType {
    PASSENGER,
    EXPRESS
};

class Train {
private:

    size_t number;
    std::string destination;
    TrainType type;
    std::string departureTime;
    std::string travelTime;

public:

    // Конструктор c параметрами
    Train(size_t, const std::string&, TrainType,
          const std::string&, const std::string&);

    // Получение номера поезда
    size_t getNumber() const;

    // Получение пункта назначения
    std::string getDestination() const;

    // Получение типа поезда
    TrainType getType() const;

    // Получение времени отправления
    std::string getDepartureTime() const;

    // Получение времени в пути
    std::string getTravelTime() const;

};

// Функция для проверки файла
void checkFile(std::ifstream&);

// Функция для заполнения вектора
void fillVector(std::ifstream&, std::vector<Train>&);

// Функция для сравнения по времени отправления
bool compareByDepartureTime(const Train&, const Train&);

// Вывод поездов в консоль
void printTrain(const Train&);

// Вывод отсортированнных поездов по времени отправления 
void printSortTrainsByDepartureTime(std::vector<Train>&);

// Вывод поездов по определенному промежутку времени отправления
void printTrainsInTimeRange(const std::vector<Train>&);

// Вывод покздов по определенному пункту назначения 
void printTrainsToDestination(const std::vector<Train>&);

// Вывод скоростных поездов по определенноиу пункту назначения 
void printExpressTrainsToDestination(const std::vector<Train>&);

// Нахождение  самого быстрого поезда, следующего в определенный пункт назначения
void findFastestTrainToDestination(const std::vector<Train>&);

#endif

