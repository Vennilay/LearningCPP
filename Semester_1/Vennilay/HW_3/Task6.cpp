#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string file_path = "task6.txt";

    std::ofstream outputFile(file_path);

    if (!outputFile.is_open()) {
        std::cout << "Ошибка открытия файла для записи!" << std::endl;
        return 1;
    }

    std::cout << "Записываем числа в файл:" << std::endl;
    for (int i = 1; i <= 10; i++) {
        outputFile << i * 5 << " ";
        std::cout << i * 5 << " ";
    }
    std::cout << std::endl;

    outputFile.close();
    std::cout << "Файл закрыт после записи.\n" << std::endl;

    std::ifstream inputFile(file_path);

    if (!inputFile.is_open()) {
        std::cout << "Ошибка открытия файла для чтения!" << std::endl;
        return 1;
    }

    int number = 0, sum = 0;
    std::cout << "Читаем числа из файла и считаем сумму:" << std::endl;

    while (inputFile >> number) {
        std::cout << number << " ";
        sum += number;
    }
    std::cout << std::endl;

    inputFile.close();
    std::cout << "\nСумма всех чисел: " << sum << std::endl;

    return 0;
}
