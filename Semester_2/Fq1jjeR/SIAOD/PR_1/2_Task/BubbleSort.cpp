#include <iostream>
#include <iomanip>
#include <chrono>
#include <fstream>
#include <vector>

using namespace std;

struct Stats {
    long long Cn = 0, Mn = 0, Tn = 0;
};

const string FILE_PATH = "D:/coding/ClionProject/Semester_2/Fq1jjeR/SIAOD/PR_1/1_Task/array_chars.txt";

void bubbleSort(char* x, int n, Stats& s) {
    s.Cn = 0; s.Mn = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            s.Cn++;
            if (x[j] > x[j + 1]) {
                swap(x[j], x[j + 1]);
                s.Mn += 3;
            }
        }
    }
    s.Tn = s.Cn + s.Mn;
}

void printHeader(string title) {
    cout << "\n[" << title << "]" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << left << setw(10) << "n"
         << setw(15) << "Время(мс)"
         << setw(15) << "Сп"
         << setw(15) << "Мп"
         << setw(15) << "Тп=Сп+Мп" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
}

void runTest(int mode) {
    vector<int> sizes = {100, 200, 500, 1000, 2000, 5000, 10000, 100000};

    if (mode == 1) printHeader("ЛУЧШИЙ СЛУЧАЙ (отсортирован)");
    else if (mode == 2) printHeader("СРЕДНИЙ СЛУЧАЙ (из файла)");
    else printHeader("ХУДШИЙ СЛУЧАЙ (обратный)");

    for (int n : sizes) {
        char* data = new char[n];

        if (mode == 1) { // Лучший
            for (int i = 0; i < n; i++) data[i] = (char)('a' + (i % 26));
        }
        else if (mode == 2) { // Из файла
            ifstream inFile(FILE_PATH);
            for (int i = 0; i < n; i++) {
                if (!(inFile >> data[i])) {
                    inFile.clear();
                    inFile.seekg(0);
                    inFile >> data[i];
                }
            }
            inFile.close();
        }
        else {
            for (int i = 0; i < n; i++) data[i] = (char)('z' - (i % 26));
        }

        Stats s;
        auto start = chrono::high_resolution_clock::now();
        bubbleSort(data, n, s);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> elapsed = end - start;

        cout << left << setw(10) << n
             << setw(15) << fixed << setprecision(4) << elapsed.count()
             << setw(15) << s.Cn
             << setw(15) << s.Mn
             << setw(15) << s.Tn << endl;

        delete[] data;
    }
}

int main() {
    runTest(1);
    runTest(2);
    runTest(3);

    return 0;
}
