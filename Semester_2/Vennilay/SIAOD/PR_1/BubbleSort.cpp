#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;

struct Result {
    long long comp;
    long long move;
    long long total;
    double ms;
};

void bubbleSort(int* arr, int n, long long& comparisons, long long& movements) {
    comparisons = 0;
    movements = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                movements++;
                arr[j] = arr[j + 1];
                movements++;
                arr[j + 1] = temp;
                movements++;
            }
        }
    }
}

void fillRandom(int* a, int n) {
    for (int i = 0; i < n; i++) a[i] = rand() % 100000;
}

void fillAscending(int* a, int n) {
    for (int i = 0; i < n; i++) a[i] = i;
}

void fillDescending(int* a, int n) {
    for (int i = 0; i < n; i++) a[i] = n - i;
}

void printArray(const int* a, int n) {
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << "\n";
}

Result runCase(int n, void (*fillFn)(int*, int), bool showArray = false) {
    int* a = new int[n];
    fillFn(a, n);

    if (showArray) {
        cout << "Исходный массив:\n";
        printArray(a, n);
    }

    long long comparisons = 0;
    long long movements = 0;

    auto t1 = high_resolution_clock::now();
    bubbleSort(a, n, comparisons, movements);
    auto t2 = high_resolution_clock::now();

    if (showArray) {
        cout << "Отсортированный массив:\n";
        printArray(a, n);
    }

    Result r;
    r.comp = comparisons;
    r.move = movements;
    r.total = comparisons + movements;
    r.ms = duration<double, milli>(t2 - t1).count();

    delete[] a;
    return r;
}

void printTableRow(int n, const Result& r) {
    cout << left << setw(10) << n
         << right << setw(14) << fixed << setprecision(4) << r.ms
         << setw(14) << r.comp
         << setw(14) << r.move
         << setw(18) << r.total << "\n";
}

void testSeries(const string& title, void (*fillFn)(int*, int), int* sizes, int cnt) {
    cout << "\n" << title << "\n";
    cout << "--------------------------------------------------------------------------\n";
    cout << left << setw(10) << "n"
         << right << setw(14) << "Время(мс)"
         << setw(14) << "Сп"
         << setw(14) << "Мп"
         << setw(18) << "Тп = Сп + Мп" << "\n";
    cout << "--------------------------------------------------------------------------\n";

    for (int i = 0; i < cnt; i++) {
        Result r = runCase(sizes[i], fillFn, false);
        printTableRow(sizes[i], r);
    }

    cout << "--------------------------------------------------------------------------\n";
}

int main() {
    srand(42);

    int demoN = 10;
    cout << "Тестирование на массиве n = 10 (случайные значения)\n";
    runCase(demoN, fillRandom, true);

    int sizes[] = {100, 200, 500, 1000, 2000, 5000, 10000, 100000};
    int cnt = sizeof(sizes) / sizeof(sizes[0]);

    testSeries("[СРЕДНИЙ СЛУЧАЙ] случайный массив", fillRandom, sizes, cnt);
    testSeries("[ХУДШИЙ СЛУЧАЙ] массив по убыванию", fillDescending, sizes, cnt);
    testSeries("[ЛУЧШИЙ СЛУЧАЙ] массив по возрастанию", fillAscending, sizes, cnt);

    cout << "\nАНАЛИЗ СЛОЖНОСТИ:\n";
    cout << "Bubble Sort без оптимизации swapped:\n";
    cout << "Лучший случай  : O(n^2)\n";
    cout << "Средний случай : O(n^2)\n";
    cout << "Худший случай  : O(n^2)\n";
    cout << "Доп. память    : O(1)\n";

    return 0;
}