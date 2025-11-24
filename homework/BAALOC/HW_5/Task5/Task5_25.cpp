#include <iostream>
#include <fstream>

bool is_sorted_strict(const std::string& s) {
    if (s.empty()) {
        return false;
    }
    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] <= s[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string filename =
        "/Users/makarleonardov/MyProjects/UniversityProjects/Informatics/LearningCPP/homework/BAALOC/HW_5/files/lines.txt";

    std::ifstream fin(filename);
    if (!fin.is_open()) {
        std::cout << "Ошибка: файл не удалось открыть.\n";
        return 1;
    }

    int count = 0;
    std::string line;

    std::cout << "Строки, где символы строго возрастают:\n";
    while (std::getline(fin, line)) {
        if (is_sorted_strict(line)) {
            std::cout << line << std::endl;
            count++;
        }
    }

    fin.close();

    std::cout << "Всего подходящих строк " << count << std::endl;

    return 0;
}
