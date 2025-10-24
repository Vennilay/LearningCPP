#include <iostream>
#include <fstream>
#include <cctype>

int main() {
    std::string filename = "files/Vennilay/HW_3/task2.txt";
    std::fstream file(filename);

    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла!" << std::endl;
        return 1;
    }

    std::cout << "Открываю: " << filename << std::endl;
    std::string line;

    while (std::getline(file, line)) {
        for (char c : line) {
            if (std::isdigit(static_cast<unsigned char>(c))) {
                std::cout << c;
            }
        }
        std::cout << std::endl;
    }
    file.close();

    return 0;
}
