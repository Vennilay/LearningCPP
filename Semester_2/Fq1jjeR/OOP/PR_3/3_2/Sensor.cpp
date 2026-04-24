#include "Sensor.h"
#include <iostream>

void Sensor::set_private_val(int val) {
    private_val = val * 3;
}

Sensor::Sensor(int priv, int pub) {
    set_private_val(priv);
    public_val = pub;
}

void Sensor::set_values(int priv, int pub) {
    set_private_val(priv);
    public_val = pub;
}

void Sensor::print() const {
    std::cout << "Sensor: " << private_val << " " << public_val << std::endl;
}