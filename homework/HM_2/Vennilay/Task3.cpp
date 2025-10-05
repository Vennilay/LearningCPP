#include <iostream>
#include <cmath>


int main() {
    double N = 0;

    std::cout << "Введите N\n";
    std::cin >> N;

    int start = ceil(N);

    for (int i = 0; i < 10; i++) {
        std::cout << start + i << std::endl;
    }

    return 0;
}

// int main() {
//     double N;
//
//     std::cout << "Введите начальное натуральное число N:\n";
//     std::cin >> N;
//
//     if (N < 1) {
//         std::cout << "N должно быть натуральным (N >= 1)\n";
//         return 1;
//     }
//
//     for (int i = 0; i < 10; ++i) {
//         std::cout << (N + i) << std::endl;
//     }
//     return 0;
// }


// int main() {
//     double N = 0;
//
//     std::cout << "Введите N\n";
//     std::cin >> N;
//
//     for (int i = 0; i < 10; i++) {
//         std::cout << N + 1 << std::endl;
//         N += 1;
//     }
//
//     return 0;
// }


