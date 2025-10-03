#include <iostream>


int main ()
{
    char station;

    std::cout << "Выбирите станцию A, B или C: ";
    std::cin >> station;

    if (station == 'A' or station == 'a')
        std::cout << "Время отправления: 13:30\nВремя в пути: 2 ч. 20 мин."
                     "\nРасстояние, км: 185\nСтоимость, руб.: 240" << std::endl;

    else if (station == 'B' or station == 'b')
        std::cout << "Время отправления: 21:02\nВремя в пути: 48 мин."
                     "\nРасстояние, км: 100\nСтоимость, руб.: 160" << std::endl;

    else if (station == 'C' or station == 'c')
        std::cout << "Время отправления: 07:45\nВремя в пути: 1 ч. 30 мин."
                     "\nРасстояние, км: 120\nСтоимость, руб.: 200" << std::endl;

    else
        std::cout << "Выберите станцию из списка!" << std::endl;

    return 0;
}
