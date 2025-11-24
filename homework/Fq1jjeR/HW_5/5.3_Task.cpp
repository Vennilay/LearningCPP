#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Проверка пути к файлу =====
string makeFilePath(const string& basePath, const string& filename) {
    return basePath + filename;
}

// ===== Ввод чисел и запись в файл =====
void createFile(const string& path) {
    int count, num;
    cout << "Сколько целых чисел хотите ввести в файл " << path << "? ";
    cin >> count;

    vector<int> numbers;
    cout << "Введите " << count << " целых чисел:\n";
    for (int i = 0; i < count; i++) {
        cin >> num;
        numbers.push_back(num);
    }

    // Сортировка чисел
    sort(numbers.begin(), numbers.end());

    // Запись в файл
    ofstream out(path);
    if (!out.is_open()) {
        cout << "Ошибка создания файла " << path << endl;
        return;
    }
    for (int n : numbers)
        out << n << " ";
    out.close();

    cout << "Файл " << path << " создан и отсортирован.\n";
}

// ===== Чтение чисел из файла =====
vector<int> readNumbers(const string& path) {
    ifstream in(path);
    vector<int> numbers;
    int num;
    while (in >> num)
        numbers.push_back(num);
    return numbers;
}

// ===== Объединение и сортировка двух массивов =====
vector<int> mergeSorted(const vector<int>& a, const vector<int>& b) {
    vector<int> result(a.size() + b.size());
    merge(a.begin(), a.end(), b.begin(), b.end(), result.begin());
    return result;
}

int main() {
    cout << "=== Задача 9 ===" << endl;
    string basePath = "D:\\Coding\\LearningCPP\\files\\Fq1jjeR\\HW_5\\";

    string fileA = makeFilePath(basePath, "A.txt");
    string fileB = makeFilePath(basePath, "B.txt");
    string fileC = makeFilePath(basePath, "C.txt");

    // Создание файлов A и B
    createFile(fileA);
    createFile(fileB);

    // Чтение и объединение
    vector<int> numbersA = readNumbers(fileA);
    vector<int> numbersB = readNumbers(fileB);

    vector<int> numbersC = mergeSorted(numbersA, numbersB);

    // Запись объединенного файла C
    ofstream outC(fileC);
    if (!outC.is_open()) {
        cout << "Ошибка создания файла " << fileC << endl;
        return 1;
    }
    for (int n : numbersC)
        outC << n << " ";
    outC.close();

    cout << "Файл C создан и содержит объединенные и отсортированные числа.\n";
    cout << "Путь файла C: " << fileC << endl;

    return 0;
}
