#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream File("../txtfiles/5.5.25.txt");
    if (File.is_open()) {
        File << "abcde" << std::endl;  // Подходит
        File << "ba" << std::endl;     // Не подходит
        File << "12356" << std::endl;  // Подходит
        File << "" << std::endl;       // Пустая (не подходит)
        File << "aaz" << std::endl;    // Подходит
        File.close();
    } else {
        std::cout << "Не удалось создать файл." << std::endl;
        return 1;
    }

    std::ifstream fin("../txtfiles/5.5.25.txt");
    if (!fin.is_open()) {
        std::cout << "Не удалось открыть файл для чтения." << std::endl;
        return 1;
    }

    int count = 0;
    std::string line;

    while (std::getline(fin, line)) {
        if (line.empty()) {
            continue;
        }

        bool isSorted = true;
        for (int i = 0; i < line.length() - 1; i++) {
            if (line[i] > line[i + 1]) {
                isSorted = false;
                break;
            }
        }

        if (isSorted) {
            count++;
        }
    }

    fin.close();

    std::cout << "Количество подходящих строк: " << count << std::endl;

    return 0;
}
