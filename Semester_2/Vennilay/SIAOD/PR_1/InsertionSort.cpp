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

void insertionSort(int* arr, int n, long long& comparisons, long long& movements) {
    comparisons = 0;
    movements = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        movements++;            // key <- arr[i]
        int j = i - 1;

        while (j >= 0) {
            comparisons++;      // comparison arr[j] > key
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                movements++;    // shift right
                j--;
            } else {
                break;
            }
        }

        arr[j + 1] = key;
        movements++;            // insert key
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
    insertionSort(a, n, comparisons, movements);
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
    cout << "Insertion Sort:\n";
    cout << "Лучший случай  : O(n)\n";
    cout << "Средний случай : O(n^2)\n";
    cout << "Худший случай  : O(n^2)\n";
    cout << "Доп. память    : O(1)\n";

    return 0;
}