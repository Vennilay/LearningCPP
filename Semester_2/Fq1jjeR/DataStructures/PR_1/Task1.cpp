#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <vector>

using namespace std;
using namespace std::chrono;

// Структура для хранения результатов замеров
struct Stats {
    long long Cn = 0; // Сравнения
    long long Mn = 0; // Перемещения
    double time_ms = 0;
};

// --- АЛГОРИТМ 1 ---
Stats delFirstMetod(char* x, int n, char key) {
    Stats s;
    auto start = high_resolution_clock::now();
    int i = 0;
    while (i <= n) {
        s.Cn++; // Сравнение x[i] == key
        if (x[i] == key) {
            for (int j = i; j < n - 1; ++j) {
                x[j] = x[j + 1];
                s.Mn++; // Перемещение элемента
            }
            n--;
        } else {
            i++;
        }
    }
    auto end = high_resolution_clock::now();
    s.time_ms = duration<double, milli>(end - start).count();
    return s;
}

// --- АЛГОРИТМ 2 ---
Stats delOtherMetod(char* x, int& n, char key) {
    Stats s;
    auto start = high_resolution_clock::now();
    int j = 0;
    for (int i = 0; i < n; ++i) {
        s.Cn++; // Сравнение x[i] != key
        x[j] = x[i];
        s.Mn++; // Копирование x[j] = x[i]
        if (x[i] != key) {
            j++;
        }
    }
    // Финальное условие из задания
    s.Cn++;
    if (n > 0 && x[0] == key) n = 0;
    else n = j;

    auto end = high_resolution_clock::now();
    s.time_ms = duration<double, milli>(end - start).count();
    return s;
}

// Функция генерации массива
void fillArray(char* arr, int n, int type, char key) {
    for (int i = 0; i < n; i++) {
        if (type == 0) arr[i] = key; // Все элементы - ключевые (худший/лучший случай)
        else if (type == 1) arr[i] = (rand() % 2 == 0) ? key : (char)('A' + rand() % 26); // Случайно
        else arr[i] = 'A'; // Ни один не равен key
    }
}

void runTest(int n, int type) {
    char* arr1 = new char;
    char* arr2 = new char;
    char key = '_';

    fillArray(arr1, n, type, key);
    for(int i=0; i<n; i++) arr2[i] = arr1[i]; // Копируем для честного сравнения

    int n2 = n;
    Stats s1 = delFirstMetod(arr1, n, key);
    Stats s2 = delOtherMetod(arr2, n2, key);

    cout << setw(8) << n << " | "
         << setw(10) << fixed << setprecision(4) << s1.time_ms << " | " << setw(10) << s1.Cn + s1.Mn << " || "
         << setw(10) << fixed << setprecision(4) << s2.time_ms << " | " << setw(10) << s2.Cn + s2.Mn << endl;

    delete[] arr1;
    delete[] arr2;
}

int main() {
    srand(time(0));
    int sizes[] = {100, 500, 1000, 2000, 5000, 10000};

    string cases[] = {"А) Все удаляются", "Б) Случайно", "В) Ничего не удаляется"};

    for (int t = 0; t < 3; t++) {
        cout << "\n=== Случай: " << cases[t] << " ===\n";
        cout << setw(8) << "n" << " | " << "Alg1 Time" << " | " << "Alg1 Tn" << "   || " << "Alg2 Time" << " | " << "Alg2 Tn" << endl;
        for (int n : sizes) {
            runTest(n, t);
        }
    }
    return 0;
}
