#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const int width = 80;   // ширина графика
    const int height = 25;  // высота графика
    const double pi = 3.14;

    const int midX = width / 2;   // центр по X
    const int midY = height / 2;  // центр по Y

    for (int y = 0; y < height; ++y) {
        for (int x = 1; x < width; ++x) {
            double angle = (2 * pi * (x - midX)) / (width - 1); // диапазон [-π, +π]
            double s = sin(angle);

            int sin_y = static_cast<int>(round(midY - s * (height - 1) / 2.0));

            // приоритет рисования:
            if (x == midX && y == midY) {
                cout << '*';  // начало координат
            }
            else if (y == sin_y) {
                cout << '*';  // график
            }
            else if (y == midY) {
                cout << '-';  // ось X
            }
            else if (x == midX) {
                cout << '|';  // ось Y
            }
            else {
                cout << ' ';  // фон
            }
        }
        cout << '\n';
    }

    return 0;
}
