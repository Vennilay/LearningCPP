#include <iostream>
#include <fstream>
#include <Windows.h>


using namespace std;

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    const string filename = R"(D:\Coding\LearningCPP\files\Fq1jjeR\HM_3\6_Task.txt)";


    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Ошибка при создании файла!" << endl;
        return 1;
    }

    cout << "Введите 10 чисел типа double:" << endl;
    for (int i = 0; i < 10; i++) {
        double num;
        cout << "Число " << (i + 1) << ": ";
        cin >> num;
        outFile << fixed << num << " ";
    }

    outFile.close();
    cout << "Файл закрыт." << endl << endl;


    ifstream inFile(filename);

    if (!inFile) {
        cerr << "Ошибка при открытии файла для чтения!" << endl;
        return 1;
    }

    double number;
    double sum = 0.0;
    int count = 0;

    cout << "Числа из файла:" << endl;
    while (inFile >> number) {
        cout << fixed << number << " ";
        sum += number;
        count++;
    }
    cout << endl;

    inFile.close();

    cout << "Прочитано чисел: " << count << endl;
    cout << fixed << "Сумма чисел: " << sum << endl;

    return 0;
}
