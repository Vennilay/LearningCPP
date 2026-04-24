#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
private:
    int private_val;
    void set_private_val(int val);

public:
    int public_val;
    Sensor(int priv, int pub);
    void set_values(int priv, int pub);
    void print() const;
};

#endif