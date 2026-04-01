#ifndef __PLAYER__H
#define __PLAYER__H

class Player {
private:
    int health;

public:
    void setHealth(int h);
    int getHealth() const;
    void changeHealth(int value);

};

#endif
