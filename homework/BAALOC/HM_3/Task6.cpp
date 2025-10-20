#include <iostream>
#include <fstream>

int writeInFile(const std::string& pathToFile) {
    std::cout << "Открытие для записи: " << pathToFile << std::endl;
    std::ofstream file(pathToFile);

    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла" << std::endl;
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        file << std::to_string(i) << std::endl;
    }

    std::cout << "Закрытие: " << pathToFile << std::endl;
    file.close();

    return 0;
}

int main() {
    std::string pathToFile = "files/BAALOC/HM_3/task6.txt";
    writeInFile(pathToFile);
}
