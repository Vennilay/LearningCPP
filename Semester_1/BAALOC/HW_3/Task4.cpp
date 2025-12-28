#include <iostream>

int gcd_division(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int gcd_subtraction(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;

    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

int main() {
    int num1 = 0, num2 = 0;

    std::cout << "Введите два числа через пробел: ";
    std::cin >> num1 >> num2;

    if (num1 == 0 and num2 == 0) {
        std::cout << "Ошибка, НОД не определён!" << std::endl;
        return 1;
    }

    num1 = std::abs(num1);
    num2 = std::abs(num2);

    std::cout << "НОД через деление: " << gcd_division(num1, num2) << std::endl;
    std::cout << "НОД через вычитание: " << gcd_subtraction(num1, num2) << std::endl;

    return 0;
}
