 #include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n = 0;
    std::cout << "Введите число n: ";
    std::cin >> n;

    int result = 1 << n;

    std::cout << "2^" << n << " = " << result << std::endl;

    return 0;
}
