#include "StorageDevice.h"

// Конструктор
StorageDevice::StorageDevice(int c) : capacity(c) {}

// Метод изменения объёма
void StorageDevice::setCapacity(int c) {
    capacity = c;
}

// Метод получения объёма. ВАЖНО: слово const должно быть и здесь!
int StorageDevice::getCapacity() const {
    return capacity;
}