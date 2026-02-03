#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    string text;
    float number, result = 0;
    ofstream fout;
    fout.open("C:\\Users\\MXLNIK\\Downloads\\text6.txt");
    cout << u8"Введите 10 чисел через пробел для записи в файл: ";
    getline(cin, text);
    fout << text;
    fout.close();

    ifstream fin;
    fin.open("C:\\Users\\MXLNIK\\Downloads\\text6.txt");
    while (fin >> number)
    {
        result += number;
    }
    fin.close();
    cout << u8"Сумма чисел: " << result << endl;
    return 0;
}
