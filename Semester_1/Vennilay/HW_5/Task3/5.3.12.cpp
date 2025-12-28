#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("../txtfiles/5.3.12.txt");
    std::string line;

    if (file.is_open()) {
        std::cout << "Содержимое файла:" << std::endl;
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cout << "Файл не найден." << std::endl;
    }

    return 0;
}
