#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std;

struct Metrics {
    long long Sp = 0;
    long long Mp = 0;
    long long Tp = 0;
    double duration = 0;
};

void delFirstMetod(char* x, int& n, char key, Metrics& m) {
    auto start = chrono::high_resolution_clock::now();

    int i = 0;
    m.Sp = 0; m.Mp = 0;

    while (i < n) {
        m.Sp++;
        if (x[i] == key) {
            for (int j = i; j < n - 1; j++) {
                x[j] = x[j + 1];
                m.Mp++;
            }
            n--;
        } else {
            i++;
        }
    }
    m.Tp = m.Sp + m.Mp;
    auto end = chrono::high_resolution_clock::now();
    m.duration = chrono::duration<double, milli>(end - start).count();
}

void printArray(const char* arr, int n, const string& msg) {
    cout << msg << ": [";
    for (int i = 0; i < n; i++) cout << arr[i] << (i == n - 1 ? "" : ", ");
    cout << "]" << endl;
}

void fillRandom(char* arr, int n) {
    for (int i = 0; i < n; i++) arr[i] = 'A' + rand() % 26;
}

void fillValue(char* arr, int n, char val) {
    for (int i = 0; i < n; i++) arr[i] = val;
}

int main() {
    srand(time(0));
    int initialSize = 10;
    char key = 'X';

    auto runTest = [&](const string& testName, void (*fill)(char*, int, char), char val) {
        int n = initialSize;
        char* arr = new char;
        fill(arr, n, val);

        Metrics m;
        cout << "\n--- Тест: " << testName << " ---" << endl;
        printArray(arr, n, "До");

        delFirstMetod(arr, n, key, m);

        printArray(arr, n, "После");
        cout << "Результаты: Sp=" << m.Sp << ", Mp=" << m.Mp
             << ", Tp=" << m.Tp << ", Время=" << fixed << setprecision(4)
             << m.duration << " мс" << endl;

        delete[] arr;
    };

    runTest("Лучший (нет ключа)", [](char* a, int s, char v){ fillValue(a, s, 'A'); }, ' ');

    runTest("Худший (все - ключи)", fillValue, key);

    runTest("Средний (случайно)", [](char* a, int s, char v){ fillRandom(a, s); }, ' ');

    return 0;
}
