#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

// Функция перевода из 10-й системы в произвольную (2–9)
string fromDecToBase(int number, int base) {
    if (number == 0) return "0";

    string result = "";
    while (number > 0) {
        result += char('0' + number % base);
        number /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}
//16
int main() {
    // Устанавливаем UTF-8 для консоли Windows
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    // Путь к файлам
    string path = "C:/Users/Denis/Documents/GitHub/LearningCPP/homework/Thesavewill/HW_5/files/";
    string inputFile = path + "input_hex.txt";
    string outputFile = path + "output_conv.txt";

    int base;
    cout << "Введите систему счисления (от 2 до 9): "; cin >> base;

    if (base < 2 || base > 9) {
        cout << "Ошибка: допустимый диапазон 2–9.\n";
        return 1;
    }
    ifstream fin(inputFile);
    if (!fin) {
        cout << "Файл " << inputFile << " не найден.\n";
        return 1;
    }

    ofstream fout(outputFile);
    string hexValue;
    while (fin >> hexValue) {
        int decimalValue = stoi(hexValue, nullptr, 16); // HEX → DEC
        fout << fromDecToBase(decimalValue, base) << endl; // DEC → выбранная система
    }

    cout << "Готово! Результаты в файле: " << outputFile << endl;

    return 0;
}
