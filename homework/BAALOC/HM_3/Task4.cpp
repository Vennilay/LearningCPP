#include <iostream>

int main() {
    int num1, num2, max_dev = 0;

    std::cout << "Введите первое и второе число через пробел: ";
    std::cin >> num1 >> num2;

    for (int i = 1; i < std::sqrt(std::max(num1, num2)) + 1; i++) {
        if (num1 % i == 0 and num2 % i == 0) {
            max_dev = std::max(i, max_dev);
        }
    }
    std::cout << "НОД: " << max_dev << std::endl;
    return 0;
}
