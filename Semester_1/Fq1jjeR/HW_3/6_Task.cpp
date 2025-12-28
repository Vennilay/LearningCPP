#include <iostream>
#include <fstream>
#include <Windows.h>


using namespace std;

int main() {

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    string filename = R"(D:\Coding\LearningCPP\files\Fq1jjeR\HW_3\6_Task.txt)";

    ofstream outFile(filename);

    if (!outFile) {
        cout << "Ошибка при создании файла!" << endl;
        return 1;
    }

    cout << "Введите 10 чисел:" << endl;
    for (int i = 0; i < 10; i++) {
        double num;
        cout << "Число " << (i + 1) << ": ";
        cin >> num;
        outFile << num << " ";
    }

    outFile.close();
    cout << "Файл закрыт." << endl;

    ifstream inFile(filename);

    double number;
    double sum = 0.0;
    int count = 0;

    cout << "Числа из файла:" << endl;

    while (inFile >> number) {
        cout << number << " ";
        sum += number;
        count++;
    }

    cout << endl;

    inFile.close();

    cout << "Прочитано чисел: " << count << endl;
    cout << "Сумма чисел: " << sum << endl;

    return 0;
}
