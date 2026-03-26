#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main() {
    srand(time(0));

    string filePath = "D:/coding/ClionProject/Semester_2/Fq1jjeR/SIAOD/PR_1/1_Task/array_chars.txt";

    size_t n;
    cout << "Введите размер массива (N): ";
    cin >> n;

    vector<char> arr(n);

    for (size_t i = 0; i < n; i++) {
        arr[i] = 'A' + (rand() % 26);
    }

    ofstream outFile(filePath);
    if (outFile.is_open()) {
        for (char c : arr) {
            outFile << c;
        }
        outFile.close();
        cout << "Готово. Массив из " << n << " символов в файле: " << filePath << endl;
    }

    return 0;
}