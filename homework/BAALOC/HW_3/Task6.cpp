#include <iostream>
#include <fstream>

int writeInFile(std::string& pathToFile) {
    std::cout << "Открытие для записи: " << pathToFile << std::endl;
    std::ofstream file(pathToFile);

    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла" << std::endl;
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        file <<  i << std::endl;
        std::cout << "Запись числа: " << i << std::endl;
    }

    std::cout << "Закрытие: " << pathToFile << std::endl;
    file.close();

    return 0;
}

double getSumFromFile(std::string& pathToFile) {
    std::ifstream file(pathToFile);
    if (!file.is_open()) {
        std::cout << "Ошибка чтения файла" << std::endl;
        return 1;
    }
    double num, sum = 0;
    while (file >> num) {
        sum += num;
    }
    file.close();
    return sum;
}

int main() {
    std::string pathToFile = "task6.txt";
    writeInFile(pathToFile);

    double sum = getSumFromFile(pathToFile);
    std::cout << "Сумма чисел в файле: " << sum << std::endl;

    return 0;
}
