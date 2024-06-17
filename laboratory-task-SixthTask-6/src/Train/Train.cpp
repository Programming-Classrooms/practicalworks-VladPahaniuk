#include "Train.hpp"

/*==========================================================*/
/*====================Конструкторы==========================*/
/*==========================================================*/

// Конструктор c параметрами
Train::Train(size_t number, const std::string& destination, TrainType type,
             const std::string& departureTime, const std::string& travelTime)
    : number(number), destination(destination), type(type),
      departureTime(departureTime), travelTime(travelTime) {}


/*==========================================================*/
/*=======================Гетеры=============================*/
/*==========================================================*/

// Получение номера поезда
size_t Train::getNumber() const {
    return number;
}

// Получение пункта назначения
std::string Train::getDestination() const {
    return destination;
}

// Получение типа поезда
TrainType Train::getType() const {
    return type;
}

// Получение времени отправления
std::string Train::getDepartureTime() const {
    return departureTime;
}

// Получение времени в пути
std::string Train::getTravelTime() const {
    return travelTime;
}


/*================================================================================*/
/*==================================== Функции ===================================*/
/*================================================================================*/

// Функция для проверки файла
void checkFile(std::ifstream &file)
{
    if (!file.good())
    {
        throw std::invalid_argument("File does not exist!");
    }

    if (!file)
    {
        throw std::ios_base::failure("File is not opened!");
    }

    if (file.peek() == EOF)
    {
        throw std::runtime_error("File is empty!");
    }
}

// Функция для заполнения вектора
void fillVector(std::ifstream& file, std::vector<Train>& trains){
    size_t number = 0;
    std::string destination = " ";
    std::string typeStr = " ";
    std::string departureTime = " ";
    std::string travelTime = " ";

     while (file>> number >> destination >> typeStr >> departureTime >> travelTime) {
        TrainType type;
        if (typeStr == "Passenger") {
            type = TrainType::PASSENGER;
        } else {
            type = TrainType::EXPRESS;
        }
        trains.emplace_back(number, destination, type, departureTime, travelTime);
    }
}

// Функция для сравнения по времени отправления
bool compareByDepartureTime(const Train& train1, const Train& train2) {
    return train1.getDepartureTime() < train2.getDepartureTime();
}

// Вывод поездов в консоль
void printTrain(const Train& train) {
    std::cout << "Train number: " << train.getNumber() << ", Destination: " << train.getDestination();
    std::cout << ", Type: ";
    if (train.getType() == TrainType::PASSENGER) {
        std::cout << "Passenger";
    } else {
        std::cout << "Express";
    }
    std::cout << ", Departure Time: " << train.getDepartureTime() << ", Travel Time: " << train.getTravelTime() << std::endl;
}

// Вывод отсортированнных поездов по времени отправления 
void printSortTrainsByDepartureTime(std::vector<Train>& trains) {
    std::sort(trains.begin(), trains.end(), compareByDepartureTime);
    for (const auto& train : trains) {
        printTrain(train);
    }

}

// Вывод поездов по определенному промежутку времени отправления
void printTrainsInTimeRange(const std::vector<Train>& trains) {
    std::string startTime;
    std::cout << "Enter start time for departure time range: ";
    std::cin >> startTime;

    std::string endTime;
    std::cout << "Enter end time for departure time range: ";
    std::cin >> endTime;

    if (startTime < "00:00"  || endTime >"23:59") {
        throw std::invalid_argument("Time cannot be negative...");
    }
    
    if(startTime > endTime){
        std::swap(startTime, endTime);
    }

    for (const auto& train : trains) {
        if (train.getDepartureTime() >= startTime && train.getDepartureTime() <= endTime) {
            printTrain(train);
        }
        
    }
}

// Вывод покздов по определенному пункту назначения 
void printTrainsToDestination(const std::vector<Train>& trains) {
    std::string destination = "";
    std::cout << "Enter destination: ";
    std::cin >> destination;

    if(destination.length() == 0 ){
        throw std::invalid_argument("Destination cannot be empty...");
    }

    std::cout << "Here are the trains with corresponding destination: " << std::endl;
    for (const auto& train : trains) {
        if (train.getDestination() == destination) {
            printTrain(train);
        }
    }

}

// Вывод скоростных поездов по определенноиу пункту назначения 
void printExpressTrainsToDestination(const std::vector<Train>& trains) {
    std::string destination = "";
    std::cout << "Enter destination: ";
    std::cin >> destination;

    if(destination.length() == 0 ){
        throw std::invalid_argument("Destination cannot be empty...");
    }

    std::cout << "Here are the Express trains with corresponding destination: " << std::endl;
    for (const auto& train : trains) {
        if (train.getDestination() == destination && train.getType() == TrainType::EXPRESS) {
            printTrain(train);
        }
    }
}

// Нахождение  самого быстрого поезда, следующего в определенный пункт назначения
void findFastestTrainToDestination(const std::vector<Train>& trains) {
    std::string destination = "";
    std::cout << "Enter destination: ";
    std::cin >> destination;

    if(destination.length() == 0 ){
        throw std::invalid_argument("Destination cannot be empty...");
    }

    std::string fastestDepartureTime;
    std::string fastestTravelTime;
    size_t fastestTrainNumber = 0;

    bool found = false;

    for (const auto& train : trains) {
        if (train.getDestination() == destination) {
            if (!found) {
                fastestDepartureTime = train.getDepartureTime();
                fastestTravelTime = train.getTravelTime();
                fastestTrainNumber = train.getNumber();
                found = true;
            } else {
                if (train.getTravelTime() < fastestTravelTime) {
                    fastestDepartureTime = train.getDepartureTime();
                    fastestTravelTime = train.getTravelTime();
                    fastestTrainNumber = train.getNumber();
                }
            }
        }
    }

    if (found) {
        std::cout << "Fastest train to " << destination << " is train number " << fastestTrainNumber << std::endl;
        std::cout << "Departure Time: " << fastestDepartureTime << ", Travel Time: " << fastestTravelTime << std::endl;
    } else {
        std::cout << "No trains found to destination: " << destination << std::endl;
    }
}

