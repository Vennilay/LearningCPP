#include <iostream>
#include <cmath>

int NODDeleniem(int number1, int number2) {
    while (number2 != 0) {
        int ostatok = number1 % number2;
        number1 = number2;
        number2 = ostatok;
    }
    return number1;
}

int NODvichitaniem(int number1, int number2) {
    if (number1 == 0) return number2;
    if (number2 == 0) return number1;

    while (number1 != number2) {
        if (number1 > number2)
            number1 -= number2;
        else
            number2 -= number1;
    }
    return number1;
}

int main() {
    int firstNumber = 0, secondNumber = 0;

    std::cout << "Введите два целых числа: ";
    std::cin >> firstNumber >> secondNumber;

    if (firstNumber == 0 && secondNumber == 0) {
        std::cout << "Ошибка: НОД(0, 0) не определён!" << std::endl;
        return 1;
    }

    int absFirst = std::abs(firstNumber);
    int absSecond = std::abs(secondNumber);

    std::cout << "\nНОД(" << firstNumber << ", " << secondNumber << "):" << std::endl;
    std::cout << "НОД (метод деления): " << NODDeleniem(absFirst, absSecond) << std::endl;
    std::cout << "НОД (метод вычитания): " << NODvichitaniem(absFirst, absSecond) << std::endl;

    return 0;
}
