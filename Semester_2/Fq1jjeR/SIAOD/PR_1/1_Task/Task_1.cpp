#include <iostream>
#include <iomanip>
#include <chrono>
#include <fstream>

using namespace std;

struct Stats {
    long long Cn = 0, Mn = 0, Tn = 0;
};

const string FILE_PATH = "D:/coding/ClionProject/Semester_2/Fq1jjeR/SIAOD/PR_1/1_Task/array_chars.txt";

void delFirstMetod(char* x, int& n, char key, Stats& s) {
    int i = 0;
    while (i < n) {
        s.Cn++;
        if (x[i] == key) {
            for (int j = i; j < n - 1; j++) {
                x[j] = x[j + 1];
                s.Mn++;
            }
            n--;
        } else i++;
    }
    s.Tn = s.Cn + s.Mn;
}

void delOtherMetod(char* x, int& n, char key, Stats& s) {
    int j = 0;
    int old_n = n;
    for (int i = 0; i < old_n; i++) {
        x[j] = x[i];
        s.Mn++;
        s.Cn++;
        if (x[i] != key) j++;
    }
    if (old_n > 0 && x[0] == key && j == 0)
        n = 0;
    else
        n = j;
    s.Tn = s.Cn + s.Mn;
}

int main() {
    int n, choice, alg;
    char key;

    cout << "Введите n: "; cin >> n;
    cout << "Введите ключ: "; cin >> key;
    cout << "1-Худший, 2-Файл, 3-Лучший, 4-Ручной: "; cin >> choice;

    char* data = new char[n];

    if (choice == 2) {
        ifstream inFile(FILE_PATH);
        if (!inFile) { delete[] data; return 1; }
        for (int i = 0; i < n; i++) {
            if (!(inFile >> data[i])) { n = i; break; }
        }
        inFile.close();
    } else if (choice == 4) {
        for (int i = 0; i < n; i++) cin >> data[i];
    } else {
        for (int i = 0; i < n; i++)
            data[i] = (choice == 1) ? key : '*';
    }

    cout << "Алгоритм (1 или 2): "; cin >> alg;

    int n_working = n;
    Stats s;
    auto start = chrono::high_resolution_clock::now();

    if (alg == 1) delFirstMetod(data, n_working, key, s);
    else delOtherMetod(data, n_working, key, s);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = end - start;

    cout << "\nВремя: " << fixed << setprecision(5) << elapsed.count() << " мс\n";
    cout << "Cn: " << s.Cn << " | Mn: " << s.Mn << " | Tn: " << s.Tn << endl;
    cout << "Осталось: " << n_working << endl;

    delete[] data;
    return 0;

}
