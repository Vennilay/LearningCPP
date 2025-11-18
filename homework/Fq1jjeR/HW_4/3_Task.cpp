
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const int width = 80;
    const int height = 25;

    const int centerX = width / 2;
    const int centerY = height / 2;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            double angle = (double)(x - centerX) / (width / 2) * M_PI;
            int sinY = centerY - (int)round(sin(angle) * (height / 2));

            if (y == sinY)
                cout << "*";
            else if (y == centerY)
                cout << "-";
            else if (x == centerX)
                cout << "|";
            else
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}

