#include <iostream>
#include <fstream>

int main() {
    std::string fileName = "files/BAALOC/HW_3/task1.txt.txt";
    std::ifstream file(fileName);

    std::cout << "Открытие: " << fileName << std::endl;
    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
    return 0;
}
