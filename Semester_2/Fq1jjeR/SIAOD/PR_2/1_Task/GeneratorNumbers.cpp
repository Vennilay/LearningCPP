#include <iostream>
#include <fstream>
#include <random>
#include <string>

int main() {
    // Указываем ваш путь. Обратите внимание на двойные слэши.
    std::string path = "D:\\coding\\ClionProject\\Semester_2\\Fq1jjeR\\SIAOD\\PR_2\\1_Task\\numbers.txt";

    int min, max, count;
    std::cout << "Введите диапазон (min max) и количество чисел: ";
    if (!(std::cin >> min >> max >> count)) return 1;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);

    std::ofstream outFile(path);

    if (outFile.is_open()) {
        for (int i = 0; i < count; ++i) {
            outFile << distrib(gen) << (i == count - 1 ? "" : "\n");
        }
        outFile.close();
        std::cout << "Файл успешно создан по адресу: " << path << std::endl;
    } else {
        std::cerr << "Не удалось создать файл. Проверьте, существует ли папка!" << std::endl;
    }

    return 0;
}
