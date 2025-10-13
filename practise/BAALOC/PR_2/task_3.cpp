#include <iostream>

int main() {
    int n = 0;

    std::cout << "Введите число n: ";
    std::cin >> n;

    int res = 1 << n;
    std::cout << "Ответ: 2^" << n << " = " << res << std::endl;

    return 0;
}
