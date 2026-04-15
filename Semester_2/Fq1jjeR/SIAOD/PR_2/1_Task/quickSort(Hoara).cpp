#include <iostream>
#include <iomanip>
#include <chrono>
#include <vector>
#include <stack>

using namespace std;

struct Stats {
    long long Cn = 0, Mn = 0, Tn = 0;
};

// Итеративная быстрая сортировка Хоара (защищена от переполнения стека)
void quickSortIterative(char* x, int n, Stats& s) {
    s.Cn = 0; s.Mn = 0;
    if (n < 2) return;

    // Стек для хранения границ подмассивов [left, right]
    stack<pair<int, int>> st;
    st.push({0, n - 1});

    while (!st.empty()) {
        int left = st.top().first;
        int right = st.top().second;
        st.pop();

        int i = left, j = right;
        char pivot = x[left + (right - left) / 2]; // Безопасный выбор опорного

        // Разделение (Partition)
        while (i <= j) {
            while (x[i] < pivot) { s.Cn++; i++; }
            s.Cn++;
            while (x[j] > pivot) { s.Cn++; j--; }
            s.Cn++;

            if (i <= j) {
                if (i < j) {
                    swap(x[i], x[j]);
                    s.Mn += 3;
                }
                i++;
                j--;
            }
        }

        // Добавляем подмассивы в стек (сначала больший, чтобы стек был меньше)
        if (left < j) st.push({left, j});
        if (i < right) st.push({i, right});
    }
    s.Tn = s.Cn + s.Mn;
}

void printHeader(string title) {
    cout << "\n[" << title << "]" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << left << setw(10) << "n"
         << setw(15) << "Время(мс)"
         << setw(15) << "Сп"
         << setw(15) << "Мп"
         << setw(15) << "Тп=Сп+Мп" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
}

void runTest(int mode) {
    vector<int> sizes = {100, 200, 500, 1000, 2000, 5000, 10000, 50000, 100000, 200000, 500000, 1000000};

    if (mode == 1) printHeader("ЛУЧШИЙ СЛУЧАЙ (рандом)");
    else if (mode == 2) printHeader("СРЕДНИЙ СЛУЧАЙ (рандом)");
    else printHeader("ХУДШИЙ СЛУЧАЙ (все одинаковые)");

    for (int n : sizes) {
        char* data = new char[n];

        if (mode == 1 || mode == 2) {
            for (int i = 0; i < n; i++) data[i] = (char)(rand() % 256);
        } else {
            // Для этой версии Хоара худший случай - массив из одинаковых элементов
            for (int i = 0; i < n; i++) data[i] = 'a';
        }

        Stats s;
        auto start = chrono::high_resolution_clock::now();
        quickSortIterative(data, n, s);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> elapsed = end - start;

        cout << left << setw(10) << n
             << setw(15) << fixed << setprecision(4) << elapsed.count()
             << setw(15) << s.Cn
             << setw(15) << s.Mn
             << setw(15) << s.Tn << endl;

        delete[] data;
    }
}

int main() {
    srand(time(0));
    runTest(1);
    runTest(2);
    runTest(3);
    return 0;
}
