#include "Bus.hpp"

Bus::Bus():numberOfRoute(0), driver("NoName"), numberOfBus(0), markOfBus("None")
{}

Bus::Bus(size_t numberOfRoute, std::string driver, size_t numberOfBus, std::string markOfBus)
{}

Bus::Bus(const Bus & other)
{
    if (this !=& other)
    {
        this->numberOfRoute = other.numberOfRoute;
        this->driver = other.driver;
        this->numberOfBus = other.numberOfBus;
        this->markOfBus = other.markOfBus;
    }
    
}

size_t Bus::getRouteNumber() const {
    return numberOfRoute ;
}

std::string Bus :: getDriver() const {
    return driver;
}

size_t Bus::getNumberOfBus() const {
    return numberOfBus;
}

std::string Bus::getMarkOfBus() const {
    return markOfBus;
}

void Bus::setRouteNumber(const Bus & other)
{
    numberOfRoute = other.numberOfRoute;
}

void Bus::setDriver(const Bus & other)
{
    driver =other.driver;
}

void Bus::setNumberOfBus(const Bus & other)
{
    numberOfBus = other.numberOfBus;
}

void Bus::setMarkeOfBus(const Bus & other)
{
    markOfBus = other.markOfBus;
}

std::istream& operator>>(std::istream& is, Bus& bus) {
    is >> bus.numberOfRoute >> bus.driver >> bus.numberOfBus >> bus.markOfBus;
    return is;
}


std::ostream& operator<<(std::ostream& os, const Bus& bus) {
    os << bus.getRouteNumber() << " " << bus.getDriver()<< " " << bus.getNumberOfBus() << " " << bus.getMarkOfBus();
    return os;
}
bool Bus::compareByNumbersOfBus(const Bus& other) const
{
    return numberOfBus < other.numberOfBus;
}

bool Bus::compareByRouteNumber(const Bus& other) const 
{
    return numberOfRoute < other.numberOfRoute;
}
