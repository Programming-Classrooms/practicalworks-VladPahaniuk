#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

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
    // Конструктор
    Train(size_t, const std::string&, TrainType,
          const std::string&, const std::string&);

    // Методы доступа к полям
    size_t getNumber() const;
    std::string getDestination() const;
    TrainType getType() const;
    std::string getDepartureTime() const;
    std::string getTravelTime() const;

};

void checkFile(std::ifstream&);
void fillVector(std::ifstream&, std::vector<Train>&);
bool compareByDepartureTime(const Train&, const Train&);
void printTrain(const Train&);
void printSortTrainsByDepartureTime(std::vector<Train>&);
void printTrainsInTimeRange(const std::vector<Train>&);
void printTrainsToDestination(const std::vector<Train>&);
void printExpressTrainsToDestination(const std::vector<Train>&);
void findFastestTrainToDestination(const std::vector<Train>&);


#endif
