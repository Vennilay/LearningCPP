#include <iostream>
#include <fstream>

int main() {
    std::string filename = "files/Vennilay/HW_3/task1.txt";
    std::fstream file(filename);

    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла!" << std::endl;
        return 1;
    }

    std::cout << "Открываю: " << filename << std::endl;
    std::string line;

    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();

    return 0;
}