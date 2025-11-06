#include <iostream>


int main() {
    std::string bright_blue = "\033[104m";    // Яркий синий фон
    std::string bright_red = "\033[101m";     // Яркий красный фон
    std::string bright_white = "\033[107m";   // Яркий белый фон
    std::string reset = "\033[0m";            // Сброс цвета

    for (int i = 0; i < 6; i++) {
        std::cout << bright_blue << "  * * * * * * * *  " << reset;
        std::cout << (i % 2 == 0 ? bright_red : bright_white) << "                              " << reset << std::endl;
    }

    for (int i = 6; i < 13; i++) {
        std::cout << (i % 2 == 0 ? bright_red : bright_white) << "                                                 " << reset << std::endl;
    }

    return 0;
}