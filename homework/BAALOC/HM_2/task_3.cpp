#include <iostream>

int main() {
    double n = 0;

    std::cout << "Введите число n: ";
    std::cin >> n;
    int N = ceil(n);

    for (int i = 1; i <= 10; i++) {
        std::cout << N << std::endl;
        N++;
    }

    return 0;
}
