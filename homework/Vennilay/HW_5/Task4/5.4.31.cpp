#include <iostream>

int main() {
    long long n;
    std::cout << "Введите число n: ";
    std::cin >> n;

    long long square = n * n;
    bool found = false;

    if (square == 0) {
        found = false;
    }

    while (square > 0) {
        long long digit = square % 10;
        if (digit == 3) {
            found = true;
            break;
        }
        square = square / 10;
    }

    if (found) {
        std::cout << "Цифра 3 входит в запись квадрата" << std::endl;
    } else {
        std::cout << "Цифра 3 НЕ входит в запись квадрата" << std::endl;
    }

    return 0;
}
