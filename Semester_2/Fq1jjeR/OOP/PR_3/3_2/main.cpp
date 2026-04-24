#include <iostream>
#include "SmartSensor.h"

int main() {
    int val1, val2;
    std::cin >> val1 >> val2;

    SmartSensor obj(val1, val2);

    obj.Sensor::print();
    obj.print();

    int single_val;
    std::cin >> single_val;

    obj.public_val = single_val;
    obj.Sensor::public_val = single_val;

    obj.print();
    obj.Sensor::print();

    int a, b;
    std::cin >> a >> b;

    if (a > 0) {
        obj.set_values(a + 1, b + 1);
        obj.Sensor::set_values(a - 1, b - 1);
        obj.print();
        obj.Sensor::print();
    } else {
        obj.Sensor::set_values(a + 1, b + 1);
        obj.set_values(a - 1, b - 1);
        obj.Sensor::print();
        obj.print();
    }

    return 0;
}