#ifndef SMARTSENSOR_H
#define SMARTSENSOR_H

#include "Sensor.h"

class SmartSensor : public Sensor {
private:
    int private_val;

public:
    int public_val;
    SmartSensor(int priv, int pub);
    void set_values(int priv, int pub);
    void print() const;
};

#endif