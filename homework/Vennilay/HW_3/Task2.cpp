#include <iostream>
#include <fstream>

int main() {
    std::string filename = "files/Vennilay/HW_3/task2.txt";
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла!" << std::endl;
        return 1;
    }

    std::cout << "Открываю: " << filename << std::endl;
    std::string line;

    while (std::getline(file, line)) {
        for (unsigned int i = 0; i < line.length(); i++) {
            if (((line[i] >= 0) && (line[i] < 48)) ||
                ((line[i] > 57) && (line[i] < 65)) ||
                ((line[i] > 90) && (line[i] < 97)) ||
                (line[i] > 122)) {
                std::cout << "Неверные данные!";
                return 1;
                 }

            if ((line[i] >= 48) && (line[i] <= 57)) {
                std::cout << line[i];
            }
        }
    }
    std::cout << std::endl;
    file.close();

    return 0;
}


