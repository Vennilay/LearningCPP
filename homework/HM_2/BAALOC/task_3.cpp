#include <iostream>

int main() {
    int n = 0;

    std::cout << "Введите число n: ";
    std::cin >> n;

    for (int i = 1; i <= 10; i++) {
        std::cout << n << std::endl;
        n++;
    }

    return 0;
}
