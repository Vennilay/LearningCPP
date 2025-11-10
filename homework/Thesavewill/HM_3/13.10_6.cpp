#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float sum = 0.0, x;
    ofstream fout("numbers.txt");
    cout << "Введите 10 чисел:";
    for (int i = 0; i < 10; i++) {
        float num;
        cin >> num;
        fout << num << " ";
    }

    fout.close();

    ifstream fin("numbers.txt");
    if (!fin) {
        cout << "Ошибка при открытии файла!";
        return 1;
    }

    while (fin >> x) {
        sum += x;
    }

    fin.close();

    cout << "Сумма чисел из файла = " << sum;

    return 0;
}
