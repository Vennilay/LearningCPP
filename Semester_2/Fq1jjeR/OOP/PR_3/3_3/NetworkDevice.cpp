#include "NetworkDevice.h"

NetworkDevice::NetworkDevice(int s) : speed(s) {}

void NetworkDevice::setSpeed(int s) {
    speed = s;
}

int NetworkDevice::getSpeed() const {
    return speed;
}