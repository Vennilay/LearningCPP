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

void insertionSort(char* x, int n, Stats& s) {
    s.Cn = 0; s.Mn = 0;
    for (int i = 1; i < n; i++) {
        s.Cn++; // Сравнение текущего с предыдущим
        if (x[i] < x[i - 1]) {
            // Если мы зашли сюда, значит случай НЕ лучший
            char temp = x[i];
            s.Mn++;
            int j = i - 1;
            while (j >= 0) {
                if (j < i - 1) s.Cn++; // Сравнения внутри цикла сдвига
                if (x[j] > temp) {
                    x[j + 1] = x[j];
                    s.Mn++;
                    j--;
                } else break;
            }
            x[j + 1] = temp;
            s.Mn++;
        }
    }
    s.Tn = s.Cn + s.Mn;
}

void runTest(int mode) {
    vector<int> sizes = {100, 200, 500, 1000, 2000, 5000, 10000};

    string title = (mode == 1) ? "ЛУЧШИЙ СЛУЧАЙ" : (mode == 2 ? "СРЕДНИЙ СЛУЧАЙ" : "ХУДШИЙ СЛУЧАЙ");
    cout << "\n[" << title << "]" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << left << setw(10) << "n" << setw(15) << "Время(мс)" << setw(15) << "Сп" << setw(15) << "Мп" << setw(15) << "Тп" << endl;
    cout << "---------------------------------------------------------------------------" << endl;

    for (int n : sizes) {
        char* data = new char[n];

        if (mode == 1) {
            // ЛУЧШИЙ: Массив строго по возрастанию (все 'a')
            for (int i = 0; i < n; i++) data[i] = 'a';
        }
        else if (mode == 2) {
            ifstream inFile(FILE_PATH);
            for (int i = 0; i < n; i++) {
                if (!(inFile >> data[i])) { inFile.clear(); inFile.seekg(0); inFile >> data[i]; }
            }
            inFile.close();
        }
        else {
            // ХУДШИЙ: Строго по убыванию
            for (int i = 0; i < n; i++) data[i] = (char)(122 - (i % 26));
            // Чтобы случай был идеально худшим для больших N, лучше заполнять так:
            // for (int i = 0; i < n; i++) data[i] = (char)(255 - (i % 256));
        }

        Stats s;
        auto start = chrono::high_resolution_clock::now();
        insertionSort(data, n, s);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> elapsed = end - start;

        cout << left << setw(10) << n << setw(15) << elapsed.count() << setw(15) << s.Cn << setw(15) << s.Mn << setw(15) << s.Tn << endl;
        delete[] data;
    }
}

int main() {
    runTest(1); // Теперь тут будет Cn = n-1 и Mn = 0
    runTest(2);
    runTest(3);
    return 0;
}
