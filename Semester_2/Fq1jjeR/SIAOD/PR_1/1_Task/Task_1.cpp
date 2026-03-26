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

void delFirstMetod(char* x, int& n, char key, Stats& s) {
    s.Cn = 0; s.Mn = 0;
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
    s.Cn = 0; s.Mn = 0;
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

void printTable(const string& title, const vector<int>& sizes, const vector<double>& times,
                const vector<long long>& cn, const vector<long long>& mn, const vector<long long>& tn) {
    cout << "\n[" << title << "]" << endl;
    cout << left << setw(10) << "n" << setw(15) << "Time(ms)" << setw(15) << "Cn"
         << setw(15) << "Mn" << setw(15) << "Tn" << endl;

    for (size_t i = 0; i < sizes.size(); i++) {
        cout << left << setw(10) << sizes[i]
             << setw(15) << fixed << setprecision(4) << times[i]
             << setw(15) << cn[i]
             << setw(15) << mn[i]
             << setw(15) << tn[i] << endl;
    }
}

void runTest(int mode, int alg, const string& title, vector<int>& sizes,
             vector<double>& times, vector<long long>& cn,
             vector<long long>& mn, vector<long long>& tn) {
    for (int n : sizes) {
        char* data = new char[n];

        if (mode == 1) { // Худший
            for (int i = 0; i < n; i++) data[i] = 'a';
        } else if (mode == 2) { // Средний (файл)
            ifstream inFile(FILE_PATH);
            if (!inFile) {
                cout << "Ошибка открытия файла!" << endl;
                delete[] data;
                return;
            }
            for (int i = 0; i < n; i++) {
                if (!(inFile >> data[i])) {
                    data[i] = 'a';
                }
            }
            inFile.close();
        } else if (mode == 3) { // Лучший
            for (int i = 0; i < n; i++) data[i] = (i % 2 == 0) ? 'a' : 'b';
        }

        char key = 'a';
        int n_working = n;
        Stats s;

        auto start = chrono::high_resolution_clock::now();

        if (alg == 1) delFirstMetod(data, n_working, key, s);
        else delOtherMetod(data, n_working, key, s);

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> elapsed = end - start;

        times.push_back(elapsed.count());
        cn.push_back(s.Cn);
        mn.push_back(s.Mn);
        tn.push_back(s.Tn);

        delete[] data;
    }
}

int main() {
    int choice, alg;

    cout << "Выберите режим:\n";
    cout << "1 - Худший (все элементы равны ключу)\n";
    cout << "2 - Средний (из файла)\n";
    cout << "3 - Лучший (нет элементов равных ключу)\n";
    cout << "4 - Ручной ввод\n";
    cout << "Ваш выбор: "; cin >> choice;

    cout << "Выберите алгоритм (1 - delFirstMetod, 2 - delOtherMetod): "; cin >> alg;

    if (choice >= 1 && choice <= 3) {
        vector<int> sizes = {100, 200, 500, 1000, 2000, 5000, 10000, 100000};
        vector<double> times;
        vector<long long> cn, mn, tn;

        string title;
        if (choice == 1) title = "ХУДШИЙ";
        else if (choice == 2) title = "СРЕДНИЙ (из файла)";
        else title = "ЛУЧШИЙ";

        runTest(choice, alg, title, sizes, times, cn, mn, tn);
        printTable(title, sizes, times, cn, mn, tn);

    } else if (choice == 4) {
        // Ручной режим - только один запуск
        int n;
        char key;

        cout << "Введите n: "; cin >> n;
        cout << "Введите ключ: "; cin >> key;

        char* data = new char[n];
        cout << "Введите " << n << " символов: ";
        for (int i = 0; i < n; i++) cin >> data[i];

        int n_working = n;
        Stats s;

        auto start = chrono::high_resolution_clock::now();

        if (alg == 1) delFirstMetod(data, n_working, key, s);
        else delOtherMetod(data, n_working, key, s);

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> elapsed = end - start;

        cout << "\nРезультаты для n = " << n << ":" << endl;
        cout << "Время: " << fixed << setprecision(5) << elapsed.count() << " мс\n";
        cout << "Cn: " << s.Cn << " | Mn: " << s.Mn << " | Tn: " << s.Tn << endl;
        cout << "Осталось элементов: " << n_working << endl;

        delete[] data;
    } else {
        cout << "Неверный выбор режима!" << endl;
    }
    return 0;
}