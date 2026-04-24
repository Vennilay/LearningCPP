#pragma once

class StorageDevice {
private:
    int capacity;
public:
    StorageDevice(int c);
    void setCapacity(int c);
    int getCapacity() const; // Обратите внимание на const
};