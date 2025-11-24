#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("../txtfiles/5.3.1.txt");

    if (inputFile.is_open()) {
        char c;
        std::cout << "Результат замены пробелов:" << std::endl;
        while (inputFile.get(c)) {
            if (c == ' ') {
                std::cout << '_';
            } else {
                std::cout << c;
            }
        }
        inputFile.close();
    } else {
        std::cout << "Ошибка открытия файла." << std::endl;
    }

    return 0;
}
