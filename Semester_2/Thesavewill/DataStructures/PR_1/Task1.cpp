#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <string>

using namespace std;

struct Metrics {
    int Sp = 0;
    int Mp = 0;
    int Tp = 0;
    double duration = 0;
};

void delFirstMetod(char* x, int& n, char key, Metrics& m) {
    cout << "Выбран первый метод" << endl;

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

void delOtherMetod(char* x, int& n, char key, Metrics& m) {
    cout << "Выбран второй метод" << endl;

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

void printArray(const char* arr, int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << (i == n - 1 ? "" : ", ");
}

void fillRandom(char* arr, int n) {
    string sel;
    cout << "Использовать заготовленный массив? д/Н: "; cin >> sel;

    if (sel == "д") for (int i = 0; i < n; i++) arr[i] = 'A' + i % 26;
    else for (int i = 0; i < n; i++) arr[i] = 'A' + rand() % 26;
}

void fillValueBad(char* arr, int n, char val) {
    for (int i = 0; i < n; i++) arr[i] = val;
}
void fillValueGood(char* arr, int n, char key, char val = 'A') {
    if (val == key) val = 'B';
    for (int i = 0; i < n; i++) arr[i] = val;
}
void fillManual(char* arr, int n) {
    cout << "Введите " << n << " элементов массива: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int main() {
    srand(time(0));
    int size, select1, select2;
    char key;
    Metrics m;
    cout << "Укажите размер массива: "; cin >> size;

    if (size <= 0) return 1;
    char* strings = new char[size];

    cout << "==================================" << endl;
    cout << "1 - ручной ввод массива" << endl;
    cout << "2 - лучший вариант для алгоритма" << endl;
    cout << "3 - случайное заполнение массива" << endl;
    cout << "4 - худший вариант для алгоритма" << endl;
    cout << "==================================" << endl;
    cout << "Ваш выбор: "; cin >> select1;
    cout << "Укажите ключ: "; cin >> key;

    switch (select1)
    {
    case 1:
        fillManual(strings, size);
        break;
    case 2:
        fillValueGood(strings, size, key);
        cout << "Массив заполнен без ключа (лучший случай)." << endl;
        break;
    case 3:
        fillRandom(strings, size);
        cout << "Массив заполнен случайно." << endl;
        break;
    case 4:
        fillValueBad(strings, size, key);
        cout << "Массив заполнен одинаковыми значениями (худший случай)." << endl;
        break;
    default:
        cout << "Ошибка выбора!";
        delete[] strings;
        return 1;
    }

    cout << endl;
    cout << "=========================" << endl;
    cout << "1 - Первый метод" << endl;
    cout << "2 - Второй метод" << endl;
    cout << "Выберите метод удаления: "; cin >> select2;
    cout << "=========================" << endl;

    if (select2 == 1) delFirstMetod(strings, size, key, m);
    if (select2 == 2) delOtherMetod(strings, size, key, m);
    if (select2 != 1 && select2 != 2) {
        delete[] strings; return 1;
    }

    cout << "\nРезультат обработки:" << endl;
    cout << "[";
    printArray(strings, size);
    cout << "]";

    cout << "\n================ МЕТРИКИ ================" << endl;
    cout << " Сравнения (Sp):      " << m.Sp << endl;
    cout << " Пересылки (Mp):      " << m.Mp << endl;
    cout << " Трудоемкость (Tp):   " << m.Tp << endl;
    cout << " Время выполнения:    " << fixed << setprecision(4) << m.duration << " мс" << endl;
    cout << "=========================================" << endl;

    delete[] strings;
    return 0;
}