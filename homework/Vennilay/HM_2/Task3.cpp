#include <iostream>
#include <cmath>

int main() {
    double N = 0;

    std::cout << "Введите N\n";
    std::cin >> N;

    int start;

    if (N < 0) {
        start = 1;
    } else {
        start = ceil(N);
    }

    for (int i = 0; i < 10; i++) {
        std::cout << start + i << std::endl;
    }

    return 0;
}