#pragma once
#include <string>
#include "NetworkDevice.h"
#include "StorageDevice.h"

class NetworkStorage : public NetworkDevice, public StorageDevice {
private:
    std::string name;
public:
    NetworkStorage(std::string n, int s, int c);
    std::string getName() const;
    void printInfo() const;
};