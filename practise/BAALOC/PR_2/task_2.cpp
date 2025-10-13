#include <iostream>

int main() {
    int x;
    std::string binary_x;

    std::cout << "Введите число X: ";
    std::cin >> x;

    while (x > 0) {
        binary_x += (x % 2) ? '1' : '0';
        x /= 2;
    }

    for (int i = 0 ; i < binary_x.length(); i++)
    {
        if (i < binary_x.length() - 1)
            binary_x[i] = '1';
        else
            binary_x[i] = '0';
    }
    std::cout << "Ответ: " << binary_x << std::endl;

    return 0;
}
