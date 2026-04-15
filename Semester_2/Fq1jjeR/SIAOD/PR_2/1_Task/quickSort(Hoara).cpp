#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <fstream>

using namespace std;

struct Metrics {
    long long comparisons = 0;
    long long moves = 0;
    double duration_ms = 0;
};

// Алгоритм разбиения Хоара
void quickSortHoare(vector<int>& arr, int low, int high, Metrics& m) {
    if (low >= high) return;

    int pivot = arr[low + (high - low) / 2];
    int i = low;
    int j = high;

    while (i <= j) {
        while (arr[i] < pivot) {
            m.comparisons++;
            i++;
        }
        m.comparisons++; // для последнего сравнения, которое нарушило цикл

        while (arr[j] > pivot) {
            m.comparisons++;
            j--;
        }
        m.comparisons++; // для последнего сравнения, которое нарушило цикл

        if (i <= j) {
            swap(arr[i], arr[j]);
            m.moves++; // обмен элементов
            i++;
            j--;
        }
    }

    if (low < j) quickSortHoare(arr, low, j, m);
    if (i < high) quickSortHoare(arr, i, high, m);
}

Metrics getQuickSortMetrics(vector<int>& arr) {
    Metrics m;
    if (arr.size() <= 1) return m;

    auto start = chrono::high_resolution_clock::now();

    quickSortHoare(arr, 0, arr.size() - 1, m);

    auto end = chrono::high_resolution_clock::now();
    m.duration_ms = chrono::duration<double, milli>(end - start).count();
    return m;
}

int main() {
    vector<int> allData;
    ifstream inputFile("numbers.txt");

    if (!inputFile) {
        cerr << "Ошибка: Не удалось найти файл numbers.txt!" << endl;
        return 1;
    }

    int num;
    while (inputFile >> num) {
        allData.push_back(num);
    }
    inputFile.close();

    vector<int> sizes = {100, 200, 500, 1000, 2000, 5000, 10000, 100000, 200000, 500000, 1000000};

    cout << "|" << setw(10) << "n"
         << " | " << setw(12) << "Время, мс   "
         << " | " << setw(12) << "Сп"
         << " | " << setw(12) << "Мп"
         << " | " << setw(12) << "Тп = Сп+Мп" << " |" << endl;
    cout << string(75, '-') << endl;

    for (int n : sizes) {
        if (n > (int)allData.size()) break;

        vector<int> testData(allData.begin(), allData.begin() + n);

        Metrics m = getQuickSortMetrics(testData);

        cout << "|" << setw(10) << n
             << " | " << setw(12) << fixed << setprecision(4) << m.duration_ms
             << " | " << setw(12) << m.comparisons
             << " | " << setw(12) << m.moves
             << " | " << setw(14) << (m.comparisons + m.moves) << " |" << endl;
    }

    return 0;
}
