#include <iostream>
#include <fstream>

int main() {
    std::string fileName = "/Users/makarleonardov/MyProjects/UniversityProjects/Informatics/LearningCPP/homework/HM_3/HM_2/task1.txt"; // gay file btw
    std::ifstream file(fileName);

    std::cout << "Открытие: " << fileName << std::endl;
    if (file.is_open()) {
        std::string line;

        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();

    } else {
        std::cout << "Ошибка открытия файла" << std::endl;
    }
    return 0;
}