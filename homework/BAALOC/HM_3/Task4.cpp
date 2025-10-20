#include <iostream>

int main() {
    int num1 = 0, num2 = 0, max_dev = 0, max_dev2 = 0;

    std::cout << "Введите первое и второе число через пробел: ";
    std::cin >> num1 >> num2;

    for (int i = 1; i <= std::max(num1, num2); i++) {
        if (num1 % i == 0 and num2 % i == 0) {
            max_dev = std::max(i, max_dev);
        }
    }
    std::cout << "НОД через деление: " << max_dev << std::endl;

    while (num1 != num2) {
        if (num1 > num2) {
            num1 -= num2;
        }
        else {
            num2 -= num1;
        }
    }
    max_dev2 = num1;
    std::cout << "НОД через вычитание: " << max_dev2 << std::endl;

    return 0;
}
