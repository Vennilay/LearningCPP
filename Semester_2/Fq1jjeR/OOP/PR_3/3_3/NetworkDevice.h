#pragma once

class NetworkDevice {
private:
    int speed;
public:
    NetworkDevice(int s);
    void setSpeed(int s);
    int getSpeed() const;
};