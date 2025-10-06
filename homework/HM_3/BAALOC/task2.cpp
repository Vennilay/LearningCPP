#include <iostream>
#include <fstream>

int main() {
    const std::string fileName =
        "/Users/makarleonardov/MyProjects/UniversityProjects/Informatics/LearningCPP/homework/HM_3/BAALOC/task2.txt";
    std::ifstream file(fileName);

    std::cout << "Открытие: " << fileName << std::endl;
    if (file.is_open()) {
        std::string line;

        while (std::getline(file, line)) {
            std::string newLine;

            for (char i : line) {
                if (std::isdigit(i) or i == ' ') {
                    newLine += i;
                }
            }

            std::size_t start = newLine.find_first_not_of(" \t");
            if (start != std::string::npos) {
                newLine = newLine.substr(start);
            }
            std::cout << newLine << std::endl;
        }

        file.close();
    }
    else {
        std::cout << "Ошибка открытия файла" << std::endl;
    }
    return 0;
}
