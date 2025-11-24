#include <iostream>
#include <fstream>

int main() {
    const std::string filename =
        "/Users/makarleonardov/MyProjects/UniversityProjects/Informatics/LearningCPP/homework/BAALOC/HW_5/task5_4.txt";
    std::vector<std::string> words;

    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::string word;
        while (inFile >> word) {
            words.push_back(word);
        }
        inFile.close();
    }

    std::cout << "Содержимое файла:" << std::endl;
    for (const auto& w : words) {
        std::cout << w << std::endl;
    }

    std::string newWord;
    std::cout << "\nВведите слово для добавления: ";
    std::cin >> newWord;

    words.push_back(newWord);
    std::sort(words.begin(), words.end());

    std::cout << "\nОбновлённый файл:" << std::endl;
    for (const auto& w : words) {
        std::cout << w << std::endl;
    }

    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& w : words) {
            outFile << w << "\n";
        }
    }

    return 0;
}
