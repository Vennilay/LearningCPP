#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <random>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <sstream>

using namespace std;

struct Metrics {
    unsigned long long comparisons = 0;
    unsigned long long movements = 0;
    double timeMs = 0.0;

    unsigned long long total() const {
        return comparisons + movements;
    }
};

int readInt(const string& prompt, int minValue = numeric_limits<int>::min()) {
    while (true) {
        cout << prompt;
        string line;
        getline(cin >> ws, line);

        stringstream ss(line);
        int value;
        char extra;

        if ((ss >> value) && !(ss >> extra) && value >= minValue) {
            return value;
        }

        cout << "Некорректный ввод. Повторите.\n";
    }
}

char readChar(const string& prompt) {
    while (true) {
        cout << prompt;
        string line;
        getline(cin >> ws, line);

        if (line.size() == 1) {
            return line[0];
        }

        cout << "Введите ровно один символ.\n";
    }
}

string readLine(const string& prompt) {
    cout << prompt;
    string s;
    getline(cin >> ws, s);
    return s;
}

void printCharArray(const vector<char>& arr, int n) {
    cout << "[";
    if (n <= 0) {
        cout << "]";
        return;
    }

    if (n <= 50) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i];
            if (i + 1 < n) cout << ' ';
        }
    } else {
        for (int i = 0; i < 25; ++i) {
            cout << arr[i] << ' ';
        }
        cout << "... ";
        for (int i = n - 25; i < n; ++i) {
            cout << arr[i];
            if (i + 1 < n) cout << ' ';
        }
    }
    cout << "]";
}

void printIntArray(const vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    cout << "[";
    if (n == 0) {
        cout << "]";
        return;
    }

    if (n <= 50) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i];
            if (i + 1 < n) cout << ' ';
        }
    } else {
        for (int i = 0; i < 25; ++i) {
            cout << arr[i] << ' ';
        }
        cout << "... ";
        for (int i = n - 25; i < n; ++i) {
            cout << arr[i];
            if (i + 1 < n) cout << ' ';
        }
    }
    cout << "]";
}

void printMetrics(const Metrics& m) {
    cout << fixed << setprecision(6);
    cout << "Сравнения: " << m.comparisons << "\n";
    cout << "Перемещения: " << m.movements << "\n";
    cout << "Тп = Сп + Мп: " << m.total() << "\n";
    cout << "Время: " << m.timeMs << " мс\n";
}

void delFirstMethod(vector<char>& x, int& n, char key, Metrics& metrics) {
    int i = 0;
    while (i < n) {
        metrics.comparisons++;
        if (x[i] == key) {
            for (int j = i; j < n - 1; ++j) {
                x[j] = x[j + 1];
                metrics.movements++;
            }
            n--;
        } else {
            i++;
        }
    }
}

void delOtherMethod(vector<char>& x, int& n, char key, Metrics& metrics) {
    int j = 0;
    for (int i = 0; i < n; ++i) {
        x[j] = x[i];
        metrics.movements++;
        metrics.comparisons++;
        if (x[i] != key) {
            j++;
        }
    }
    n = j;
}

void bubbleSort(vector<int>& arr, Metrics& metrics) {
    int n = static_cast<int>(arr.size());
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            metrics.comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                metrics.movements++;
                arr[j] = arr[j + 1];
                metrics.movements++;
                arr[j + 1] = temp;
                metrics.movements++;
            }
        }
    }
}

void insertionSort(vector<int>& arr, Metrics& metrics) {
    int n = static_cast<int>(arr.size());
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        metrics.movements++;
        int j = i - 1;

        while (j >= 0) {
            metrics.comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                metrics.movements++;
                j--;
            } else {
                break;
            }
        }

        arr[j + 1] = key;
        metrics.movements++;
    }
}

vector<char> buildCharArray() {
    mt19937 rng(random_device{}());

    while (true) {
        cout << "\nСпособ ввода символьного массива:\n";
        cout << "1. Ввести строку вручную\n";
        cout << "2. Сгенерировать случайный массив\n";
        cout << "3. Заполнить одним символом\n";
        int mode = readInt("Ваш выбор: ", 1);

        if (mode == 1) {
            string s = readLine("Введите строку: ");
            return vector<char>(s.begin(), s.end());
        }

        if (mode == 2) {
            int n = readInt("Введите длину массива: ", 1);
            char left = readChar("Введите левую границу символов: ");
            char right = readChar("Введите правую границу символов: ");
            if (left > right) swap(left, right);

            uniform_int_distribution<int> dist(static_cast<int>(left), static_cast<int>(right));
            vector<char> arr(n);
            for (int i = 0; i < n; ++i) {
                arr[i] = static_cast<char>(dist(rng));
            }
            return arr;
        }

        if (mode == 3) {
            int n = readInt("Введите длину массива: ", 1);
            char fill = readChar("Введите символ заполнения: ");
            return vector<char>(n, fill);
        }

        cout << "Нет такого пункта.\n";
    }
}

vector<int> buildIntArray() {
    mt19937 rng(random_device{}());

    while (true) {
        cout << "\nСпособ ввода числового массива:\n";
        cout << "1. Ввести вручную\n";
        cout << "2. Сгенерировать случайный массив\n";
        cout << "3. Уже отсортированный по возрастанию\n";
        cout << "4. Уже отсортированный по убыванию\n";
        int mode = readInt("Ваш выбор: ", 1);

        if (mode == 1) {
            int n = readInt("Введите длину массива: ", 1);
            vector<int> arr(n);
            cout << "Введите " << n << " целых чисел:\n";
            for (int i = 0; i < n; ++i) {
                arr[i] = readInt("Элемент [" + to_string(i) + "]: ");
            }
            return arr;
        }

        if (mode == 2) {
            int n = readInt("Введите длину массива: ", 1);
            int left = readInt("Введите левую границу диапазона: ");
            int right = readInt("Введите правую границу диапазона: ");
            if (left > right) swap(left, right);

            uniform_int_distribution<int> dist(left, right);
            vector<int> arr(n);
            for (int i = 0; i < n; ++i) {
                arr[i] = dist(rng);
            }
            return arr;
        }

        if (mode == 3) {
            int n = readInt("Введите длину массива: ", 1);
            vector<int> arr(n);
            for (int i = 0; i < n; ++i) {
                arr[i] = i + 1;
            }
            return arr;
        }

        if (mode == 4) {
            int n = readInt("Введите длину массива: ", 1);
            vector<int> arr(n);
            for (int i = 0; i < n; ++i) {
                arr[i] = n - i;
            }
            return arr;
        }

        cout << "Нет такого пункта.\n";
    }
}

void runDelFirst() {
    vector<char> arr = buildCharArray();
    char key = readChar("Введите ключевой символ для удаления: ");
    int n = static_cast<int>(arr.size());

    cout << "\nИсходный массив: ";
    printCharArray(arr, n);
    cout << "\n";

    Metrics metrics;
    auto start = chrono::high_resolution_clock::now();
    delFirstMethod(arr, n, key, metrics);
    auto finish = chrono::high_resolution_clock::now();
    metrics.timeMs = chrono::duration<double, milli>(finish - start).count();

    cout << "\nРезультат после delFirstMethod: ";
    printCharArray(arr, n);
    cout << "\n";
    cout << "Эффективная длина: " << n << "\n";
    printMetrics(metrics);
}

void runDelOther() {
    vector<char> arr = buildCharArray();
    char key = readChar("Введите ключевой символ для удаления: ");
    int n = static_cast<int>(arr.size());

    cout << "\nИсходный массив: ";
    printCharArray(arr, n);
    cout << "\n";

    Metrics metrics;
    auto start = chrono::high_resolution_clock::now();
    delOtherMethod(arr, n, key, metrics);
    auto finish = chrono::high_resolution_clock::now();
    metrics.timeMs = chrono::duration<double, milli>(finish - start).count();

    cout << "\nРезультат после delOtherMethod: ";
    printCharArray(arr, n);
    cout << "\n";
    cout << "Эффективная длина: " << n << "\n";
    printMetrics(metrics);
}

void runBubble() {
    vector<int> arr = buildIntArray();

    cout << "\nИсходный массив: ";
    printIntArray(arr);
    cout << "\n";

    Metrics metrics;
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(arr, metrics);
    auto finish = chrono::high_resolution_clock::now();
    metrics.timeMs = chrono::duration<double, milli>(finish - start).count();

    cout << "\nРезультат после bubbleSort: ";
    printIntArray(arr);
    cout << "\n";
    printMetrics(metrics);
}

void runInsertion() {
    vector<int> arr = buildIntArray();

    cout << "\nИсходный массив: ";
    printIntArray(arr);
    cout << "\n";

    Metrics metrics;
    auto start = chrono::high_resolution_clock::now();
    insertionSort(arr, metrics);
    auto finish = chrono::high_resolution_clock::now();
    metrics.timeMs = chrono::duration<double, milli>(finish - start).count();

    cout << "\nРезультат после insertionSort: ";
    printIntArray(arr);
    cout << "\n";
    printMetrics(metrics);
}

int main() {
    while (true) {
        cout << "\n========== МЕНЮ ==========\n";
        cout << "1. Запустить delFirstMethod\n";
        cout << "2. Запустить delOtherMethod\n";
        cout << "3. Запустить bubbleSort\n";
        cout << "4. Запустить insertionSort\n";
        cout << "0. Выход\n";

        int choice = readInt("Выберите пункт: ", 0);

        if (choice == 0) {
            cout << "Программа завершена.\n";
            break;
        }

        if (choice == 1) runDelFirst();
        else if (choice == 2) runDelOther();
        else if (choice == 3) runBubble();
        else if (choice == 4) runInsertion();
        else cout << "Нет такого пункта меню.\n";
    }

    return 0;
}
