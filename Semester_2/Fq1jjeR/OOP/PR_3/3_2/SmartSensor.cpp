#include "SmartSensor.h"
#include <iostream>

SmartSensor::SmartSensor(int priv, int pub) : Sensor(priv, pub) {
    private_val = priv;
    public_val = pub;
}

void SmartSensor::set_values(int priv, int pub) {
    private_val = priv;
    public_val = pub;
}

void SmartSensor::print() const {
    std::cout << "SmartSensor: " << private_val << " " << public_val << std::endl;
}