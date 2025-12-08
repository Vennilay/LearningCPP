#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;
//9
int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    string path = "C:/Users/Denis/Documents/GitHub/LearningCPP/homework/Thesavewill/HW_5/files/";
    string fileA = path + "A.txt";
    string fileB = path + "B.txt";
    string fileC = path + "C.txt";

    vector<int> numbers;
    int num;

    // Чтение чисел из файла A
    ifstream inA(fileA);
    while (inA >> num) numbers.push_back(num);
    inA.close();

    // Чтение чисел из файла B
    ifstream inB(fileB);
    while (inB >> num) numbers.push_back(num);
    inB.close();

    // Сортировка и запись в файл C
    sort(numbers.begin(), numbers.end());
    ofstream outC(fileC);
    for (int n : numbers) outC << n << " ";
    outC.close();

    cout << "Файлы успешно объединены и отсортированы в " << fileC << endl;

    return 0;
}
