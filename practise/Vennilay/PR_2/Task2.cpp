#include <iostream>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int x = 0;

    std::string binary;

    std::cout << "Введите число X: ";
    std::cin >> x;

    while (x > 0) {
        binary += (x % 2) ? '1' : '0';
        x /= 2;
    }

    for (int i = 0 ; i < binary.length(); i++)
    {
        if (i < binary.length() - 1)
            binary[i] = '1';
        else
            binary[i] = '0';
    }
    std::cout << "Ответ: " << binary << std::endl;

    return 0;
}
