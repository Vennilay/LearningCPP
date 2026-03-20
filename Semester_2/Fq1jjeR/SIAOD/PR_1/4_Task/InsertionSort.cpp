#include <iostream>
#include <iomanip>
#include <chrono>
#include <vector>

using namespace std;

struct Stats {
    long long Cn = 0, Mn = 0, Tn = 0;
};

void insertionSort(int* x, int n, Stats& s) {
    s.Cn = 0; s.Mn = 0;
    for (int i = 1; i < n; i++) {
        int temp = x[i];
        int j = i - 1;

        while (j >= 0) {
            s.Cn++;
            if (x[j] > temp) {
                x[j + 1] = x[j];
                s.Mn++;
                j--;
            } else {
                break;
            }
        }
        if (j + 1 != i) {
            x[j + 1] = temp;
            s.Mn++;
        }
    }
    s.Tn = s.Cn + s.Mn;
}

void runTest(int mode) {
    vector<int> sizes = {100, 200, 500, 1000, 2000, 5000, 10000, 100000};
    string title = (mode == 1) ? "ЛУЧШИЙ" : (mode == 2 ? "СРЕДНИЙ" : "ХУДШИЙ");

    cout << "\n[" << title << "]" << endl;
    cout << left << setw(10) << "n" << setw(15) << "Time(ms)" << setw(15) << "Cn" << setw(15) << "Mn" << setw(15) << "Tn" << endl;

    for (int n : sizes) {
        int* data = new int[n];
        if (mode == 1) {
            for (int i = 0; i < n; i++) data[i] = i;
        } else if (mode == 2) {
            for (int i = 0; i < n; i++) data[i] = rand() % 100000;
        } else {
            for (int i = 0; i < n; i++) data[i] = n - i;
        }

        Stats s;
        auto start = chrono::high_resolution_clock::now();
        insertionSort(data, n, s);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> elapsed = end - start;

        cout << left << setw(10) << n << setw(15) << fixed << setprecision(4) << elapsed.count()
             << setw(15) << s.Cn << setw(15) << s.Mn << setw(15) << s.Tn << endl;
        delete[] data;
    }
}

int main() {
    runTest(1);
    runTest(2);
    runTest(3);
    return 0;
}
