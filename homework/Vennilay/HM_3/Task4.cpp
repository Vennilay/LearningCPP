#include <iostream>

int NODDeleniem(int number1, int number2) {
    while (number2 != 0) {
        int ostatok = number1 % number2;
        number1 = number2;
        number2 = ostatok;
    }
    return number1;
}

int NODvichitaniem(int number1, int number2) {
    while (number1 != number2) {
        if (number1 > number2)
            number1 -= number2;
        else
            number2 -= number1;
    }
    return number1;
}

int main() {
    int firstNumber, secondNumber;

    std::cout << "Введите два числа: ";
    std::cin >> firstNumber >> secondNumber;

    std::cout << "НОД (метод деления): "
              << NODDeleniem(firstNumber, secondNumber) << std::endl;

    std::cout << "НОД (метод вычитания): "
              << NODvichitaniem(firstNumber, secondNumber) << std::endl;

    return 0;
}
