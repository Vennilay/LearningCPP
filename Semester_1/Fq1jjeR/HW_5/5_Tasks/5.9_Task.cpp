#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    string basePath = "files";
    string fileA = basePath + "A.txt", fileB = basePath + "B.txt", fileC = basePath + "C.txt";


    // Создание файла A
    int count, num;
    cout << "Сколько целых чисел хотите ввести в файл A: ";
    cin >> count;

    vector<int> numbersA;
    cout << "Введите " << count << " целых чисел:\n";
    for (int i = 0; i < count; i++) {
        cin >> num;
        numbersA.push_back(num);
    }
    sort(numbersA.begin(), numbersA.end());

    ofstream outA(fileA);
    for (int n : numbersA)
        outA << n << " ";
    outA.close();

    // Создание файла B
    cout << "Сколько целых чисел хотите ввести в файл B: ";
    cin >> count;

    vector<int> numbersB;
    cout << "Введите " << count << " целых чисел:\n";
    for (int i = 0; i < count; i++) {
        cin >> num;
        numbersB.push_back(num);
    }
    sort(numbersB.begin(), numbersB.end());

    ofstream outB(fileB);
    for (int n : numbersB)
        outB << n << " ";
    outB.close();

    // Объединение и сортировка
    vector<int> numbersC(numbersA.size() + numbersB.size());
    merge(numbersA.begin(), numbersA.end(), numbersB.begin(), numbersB.end(), numbersC.begin());

    // Запись файла C
    ofstream outC(fileC);
    for (int n : numbersC)
        outC << n << " ";
    outC.close();

    cout << "Файл C создан и содержит объединенные и отсортированные числа.";

    return 0;
}