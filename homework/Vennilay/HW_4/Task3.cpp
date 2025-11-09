#include <iostream>
#include <cmath>

int main() {
    const int HEIGHT = 20;
    const int WIDTH = 160;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double angle = 6 * M_PI * x / WIDTH;
            double sinValue = std::sin(angle);
            int sinY = HEIGHT / 2 - static_cast<int>(sinValue * HEIGHT / 3.0);

            if (x == 0 && y == 0) {
                std::cout << "y ^";
            } else if (x == 0 && y < HEIGHT - 1) {
                std::cout << "  |";
            } else if (y == HEIGHT / 2 && x == WIDTH - 1) {
                std::cout << "> x";
            } else if (y == HEIGHT / 2 && x > 0) {
                std::cout << '-';
            } else if (y == sinY) {
                std::cout << '*';
            } else {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }

    return 0;
}
