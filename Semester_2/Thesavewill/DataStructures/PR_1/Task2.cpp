#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <vector>

using namespace std;

struct Metrics {
    long long Sp = 0;
    long long Mp = 0;
    long long Tp = 0;
    double duration = 0;
};

void delOtherMetod(char* x, int& n, char key, Metrics& m) {
    auto start = chrono::high_resolution_clock::now();
    m.Sp = 0; m.Mp = 0;

    if (n <= 0) return;

    int j = 0;
    for (int i = 0; i < n; i++) {
        x[j] = x[i];
        m.Mp++;
        m.Sp++;
        if (x[i] != key) {
            j++;
        }
    }

    m.Sp++;
    if (n > 0 && x[0] == key && j == 0) {
        n = 0;
    } else {
        n = j;
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

int main() {
    srand(time(0));
    const int size = 10;
    char key = 'X';

    auto runTest = [&](string name, string type) {
        int n = size;
        char* arr = new char;

        if (type == "best") for(int i=0; i<n; i++) arr[i] = 'A';
        else if (type == "worst") for(int i=0; i<n; i++) arr[i] = key;
        else for(int i=0; i<n; i++) arr[i] = (rand()%2) ? key : (char)('A' + rand()%26);

        Metrics m;
        cout << "\n--- " << name << " ---" << endl;
        printArray(arr, n, "До");

        delOtherMetod(arr, n, key, m);

        printArray(arr, n, "После");
        cout << "Сп: " << m.Sp << ", Мп: " << m.Mp << ", Тп: " << m.Tp
             << ", Время: " << fixed << setprecision(4) << m.duration << " ms" << endl;

        delete[] arr;
    };

    runTest("ЛУЧШИЙ СЛУЧАЙ (ключей нет)", "best");
    runTest("ХУДШИЙ СЛУЧАЙ (все - ключи)", "worst");
    runTest("СРЕДНИЙ СЛУЧАЙ (рандом)", "average");

    return 0;
}
