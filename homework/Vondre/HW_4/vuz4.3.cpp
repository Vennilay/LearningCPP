#include <iostream>
#include <cmath>

int main() {
    const int height = 31;
    const int width = 160;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double angle = 4 * M_PI * x / width;
            double sinValue = std::sin(angle);
            int y_pos = height / 2 - static_cast<int>(sinValue * height / 3);

            if (x == 0 and y == 0) {
                std::cout << "y ^";
            } else if (x == 0 and y < height - 1) {
                std::cout << "  |";
            } else if (y == height / 2 and x == width - 1) {
                std::cout << "> x";
            } else if (y == height / 2 and x > 0) {
                std::cout << '-';
            } else if (y == y_pos) {
                std::cout << '*';
            } else {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }

    return 0;
}
