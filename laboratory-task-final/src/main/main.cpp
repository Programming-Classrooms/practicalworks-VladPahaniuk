#include "src/Bus/Bus.hpp"

void checkFile(std::ifstream& file)
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

void readBusesFromFile(const std::string& filename, std::vector<Bus>& buses) {
    std::ifstream file(filename);
    checkFile(file);

    Bus bus;
    while (file >> bus) {
        buses.push_back(bus);
    }

    file.close();
}

void printVec(std::vector<Bus>& buses){
    for(const auto& it : buses){
        std::cout << it << " ";
    }
}
void sortBusesByNumberOfBus(std::vector<Bus>& buses) {
    std::sort(buses.begin(), buses.end(), [](const Bus& a, const Bus& b) {
        return a.compareByNumbersOfBus(b);
        });
}

void sortBusesByRouteNumber(std::vector<Bus>& buses) {
    std::sort(buses.begin(), buses.end(), [](const Bus& a, const Bus& b) {
        return a.compareByRouteNumber(b);
        });
}


void populateBusMap(const std::vector<Bus>& buses, std::map<size_t, std::vector<Bus>>& busMap) {
    for (const auto& bus : buses) {
        busMap[bus.getNumberOfBus()].push_back(bus);
    }
}	


void printBusForRoute(const std::map<size_t, std::vector<Bus>>& busMap, size_t routeNumber) {
    auto it = busMap.find(routeNumber);
    if (it != busMap.end()) {
        std::cout << "Bus for route " << routeNumber << ":\n";
        for (const auto& bus : it->second) {
            std::cout << bus << std::endl;
        }
    }
    else {
        std::cout << "Bus " << routeNumber << " not found." << std::endl;
    }

}

void printAllRoutes(const std::map<size_t, std::vector<Bus>>& busMap) {
    std::cout << "List of all routes:\n";
    for (const auto& pair : busMap) {
        std::cout << "Route " << pair.first << std::endl;
    }
}

// void delteInfo(std::map<size_t, std::vector<Bus>>& busMap, size_t busNumber, size_t busIndex) {
//     auto it = busMap.find(busNumber);
//     if (it != busMap.end() && busIndex < it->second.size()) {
//         it->second.erase();
//         std::cout << "Bus ." << std::endl;
//     }
//     else {
//         std::cout << "Route or bus index not found." << std::endl;
//     }
// }


void printBusMap(const std::map<size_t, std::vector<Bus>>& busMap) {
    for (const auto& pair : busMap) {
        size_t routeNumber = pair.first;
        const std::vector<Bus>& buses = pair.second;

        std::cout << "Route Number: " << routeNumber << std::endl;
        for (const auto& bus : buses) {
            std::cout << "Bus Number: " << bus.getNumberOfBus()
                << ", Driver: " << bus.getDriver()
                << ", Mark: " << bus.getMarkOfBus() << std::endl;
        }
        std::cout << std::endl;
    }
}

// bool findRouteMax(const std::map<size_t, std::vector<Bus>>& busMap, std::pair<size_t, std::string>& result) {
//     for (const auto& pair : busMap) {
//         size_t routeNumber = pair.first;
//         const std::vector<Bus>& buses = pair.second;

//         for (const auto& bus : buses) {
//             if (bus.getDriver() == driverName()+) {
//                 result = { bus.getNumberOfBus(), bus.getMarkOfBus() };
//                 std::cout << "Driver " << driverName << " works on route " << routeNumber
//                     << " with bus number " << bus.getNumberOfBus()
//                     << " and mark " << bus.getMarkOfBus() << std::endl;
//                 return true;
//             }
//         }
//     }
//     return false;
// }

int main()
{
	Bus bus;
	std::vector<Bus> buses;
	readBusesFromFile("src/files/Bus.txt", buses);

    std::cout << "Bus sorted by number of bus."<< std::endl; 
    sortBusesByNumberOfBus(buses);


    printVec(buses);


    std::cout << "Bus sorted by route number of bus."<< std::endl; 
    sortBusesByRouteNumber(buses);

    std::map<size_t, std::vector<Bus>> busMap;
    populateBusMap(buses, busMap);

    printBusMap(busMap);

    
    printAllRoutes(busMap);
    size_t routeNumber = 100;

    printBusForRoute(busMap, routeNumber);




	return 0;
}

