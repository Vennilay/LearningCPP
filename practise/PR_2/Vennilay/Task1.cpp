#include <iostream>
#include <windows.h>
#include <cctype>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char station;

    std::cout << "Введите станцию (A, B или C): ";
    std::cin >> station;

    switch (tolower(station)) {
        case 'a':
            std::cout << "Выбрана станция A\nВремя отправления: 13:30\nВремя в пути: 2ч. 20мин\nРасстояние, км: 185\nСтоимость, руб: 240" << std::endl;
            break;
        case 'b':
            std::cout << "Выбрана станция B\nВремя отправления: 21:02\nВремя в пути: 48 мин.\nРасстояние, км: 100\nСтоимость, руб: 160" << std::endl;
            break;
        case 'c':
            std::cout << "Выбрана станция C\nВремя отправления: 07:45\nВремя в пути: 1ч. 30 мин\nРасстояние, км: 120\nСтоимость, руб: 200" << std::endl;
            break;
    }

    return 0;
}
