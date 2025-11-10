#include <iostream>
#include <cmath>

int main() {
    const int width = 80;   // ширина графика
    const int height = 25;  // высота графика
    const double pi = 3.14;

    const int midX = width / 2;   // центр по X
    const int midY = height / 2;  // центр по Y

    for (int y = 0; y < height; ++y) {
        for (int x = 1; x < width; ++x) {
            double angle = (2 * pi * (x - midX)) / (width - 1); // диапазон [-π, +π]
            double s = std::sin(angle);

            int sin_y = static_cast<int>(std::round(midY - s * (height - 1) / 2.0));

            // приоритет рисования:
            if (x == midX && y == midY) {
                std::cout << '*';  // начало координат
            }
            else if (y == sin_y) {
                std::cout << '*';  // график
            }
            else if (y == midY) {
                std::cout << '-';  // ось X
            }
            else if (x == midX) {
                std::cout << '|';  // ось Y
            }
            else {
                std::cout << ' ';  // фон
            }
        }
        std::cout << '\n';
    }

    return 0;
}
