#include <iostream>
#include <cmath>
/*
using namespace std;


int main() {
    int width = 80;
    int height = 20;
    for (int y = 0; y < height; ++y) {
        double val_y = 1.0 - 2.0 * y / (height-1); // Y от +1 до -1
        for (int x = 0; x < width; ++x) {
            double angle = 2 * M_PI * x / width;
            double val_x = sin(angle);
            if (fabs(val_x - val_y) < 0.05)
                cout << "*";
            else if (y == height/2)
                cout << "-";
            else
                cout << " ";
        }
        cout << endl;
    }
}
*/

int main() {
    int HEIGHT = 40;
    int WIDTH = 80;

    std::string verticalLine;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == y) {
                verticalLine += '-';
            }
            else {
                verticalLine += ' ';
            }
        }
    }
    for (char c : verticalLine) {
        std::cout << c << std::endl;
    }
}