#ifndef BUS_HPP
#define BUS_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

 class Bus
 {
   public:

    size_t numberOfRoute;
    std::string driver;
    size_t numberOfBus;
    std::string markOfBus;

    Bus();
    Bus(size_t, std::string, size_t, std::string);
    Bus(const Bus&);
    ~Bus(){}

    friend std::istream& operator>>(std::istream&, Bus&);
    friend std::ostream& operator<<(std::ostream&, const Bus&);
    
    size_t getRouteNumber() const;
    std::string getDriver() const;
    size_t getNumberOfBus() const; 
    std::string getMarkOfBus() const;

   void setRouteNumber(const Bus&);
   void setDriver(const Bus&);
   void setNumberOfBus(const Bus&);
   void setMarkeOfBus(const Bus&);

   bool compareByNumbersOfBus(const Bus&) const;
   bool compareByRouteNumber(const Bus&) const ;

};
 
 
#endif
