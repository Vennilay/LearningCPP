#include "NetworkStorage.h"
#include <iostream>

NetworkStorage::NetworkStorage(std::string n, int s, int c)
    : NetworkDevice(s), StorageDevice(c), name(n) {}

std::string NetworkStorage::getName() const {
    return name;
}

void NetworkStorage::printInfo() const {
    std::cout << name << " " << getSpeed() << " " << getCapacity() << std::endl;
}