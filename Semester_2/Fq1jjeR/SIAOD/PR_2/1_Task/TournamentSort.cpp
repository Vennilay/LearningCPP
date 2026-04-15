#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <chrono>
#include <iomanip>
#include <fstream>

using namespace std;

// Структура для хранения метрик
struct Metrics {
    long long comparisons = 0; // Сп
    long long moves = 0;       // Мп
    double duration_ms = 0;    // Время в мс
};

// Функция турнирной сортировки с подсчетом метрик
Metrics tournamentSort(vector<int>& arr) {
    Metrics m;
    int n = arr.size();
    if (n <= 1) return m;

    auto start = chrono::high_resolution_clock::now();

    int size = 1;
    while (size < n) size *= 2;

    vector<int> tree(2 * size - 1, INT_MAX);

    // 1. Заполнение листьев
    for (int i = 0; i < n; ++i) {
        tree[size - 1 + i] = arr[i];
        m.moves++; // копирование элемента в дерево
    }

    // 2. Построение дерева (исправленный подсчёт)
    for (int i = size - 2; i >= 0; --i) {
        m.comparisons++; // сравнение для выбора минимума
        if (tree[2 * i + 1] <= tree[2 * i + 2]) {
            tree[i] = tree[2 * i + 1];
        } else {
            tree[i] = tree[2 * i + 2];
        }
        m.moves++; // запись результата в родителя
    }

    // 3. Извлечение элементов
    for (int i = 0; i < n; ++i) {
        int winner = tree[0];
        arr[i] = winner;
        m.moves++; // запись в результирующий массив

        // Поиск пути от корня к листу-победителю (исправлен для дубликатов)
        int idx = 0;
        while (idx < size - 1) {
            m.comparisons++; // сравнение левого и правого потомка
            if (tree[2 * idx + 1] <= tree[2 * idx + 2]) {
                idx = 2 * idx + 1;
            } else {
                idx = 2 * idx + 2;
            }
        }

        // Удаление победителя
        tree[idx] = INT_MAX;
        m.moves++; // запись бесконечности

        // Восстановление дерева (обновление родителей)
        while (idx > 0) {
            idx = (idx - 1) / 2;
            m.comparisons++; // сравнение для выбора минимума
            if (tree[2 * idx + 1] <= tree[2 * idx + 2]) {
                tree[idx] = tree[2 * idx + 1];
            } else {
                tree[idx] = tree[2 * idx + 2];
            }
            m.moves++; // запись результата в родителя
        }
    }

    auto end = chrono::high_resolution_clock::now();
    m.duration_ms = chrono::duration<double, milli>(end - start).count();
    return m;
}

int main() {
    // 1. Загрузка всех данных из файла
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

    // 2. Список размеров для таблицы
    vector<int> sizes = {100, 200, 500, 1000, 2000, 5000, 10000, 100000, 200000, 500000, 1000000};

    // 3. Вывод шапки таблицы
    cout << "|" << setw(10) << "n"
         << " | " << setw(12) << "Время, мс   "
         << " | " << setw(12) << "Сп"
         << " | " << setw(12) << "Мп"
         << " | " << setw(12) << "Тп = Сп+Мп" << " |" << endl;
    cout << string(75, '-') << endl;

    // 4. Цикл по размерам
    for (int n : sizes) {
        if (n > (int)allData.size()) break;

        // Создаём копию для каждого размера
        vector<int> testData(allData.begin(), allData.begin() + n);

        Metrics m = tournamentSort(testData);

        cout << "|" << setw(10) << n
             << " | " << setw(12) << fixed << setprecision(4) << m.duration_ms
             << " | " << setw(12) << m.comparisons
             << " | " << setw(12) << m.moves
             << " | " << setw(14) << (m.comparisons + m.moves) << " |" << endl;
    }

    return 0;
}