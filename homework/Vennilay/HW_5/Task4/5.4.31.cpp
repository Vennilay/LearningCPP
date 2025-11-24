#include <iostream>

int main() {
    long long n;
    std::cout << "Введите целое число n: ";
    std::cin >> n;

    long long sq = n * n;
    sq = std::llabs(sq);

    bool has3 = false;

    if (sq == 0) {
        has3 = false;
    } else {
        while (sq > 0) {
            const int d = static_cast<int>(sq % 10);
            if (const int d = static_cast<int>(sq % 10); d == 3) {
                has3 = true;
                break;
            }
            sq /= 10;
        }
    }

    if (has3) {
        std::cout << "Цифра 3 входит в запись n^2." << std::endl;
    } else {
        std::cout << "Цифра 3 не входит в запись n^2." << std::endl;
    }

    return 0;
}
