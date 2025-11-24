#include <iostream>
#include <fstream>
#include <vector>
#include <numeric> // для std::gcd
using namespace std;

// ===== ПУТЬ К ФАЙЛАМ =====
const string BASE_PATH = "D:\\Coding\\LearningCPP\\files\\Fq1jjeR\\HW_5\\";
const string numbersFile = BASE_PATH + "numbers.txt";
const string primesFile  = BASE_PATH + "primes.txt";

// ===== Проверка числа на простоту =====
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// ===== Вычисление НОК двух чисел =====
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    int count;
    cout << "Сколько натуральных чисел хотите ввести? ";
    cin >> count;

    vector<int> numbers;
    int num;

    cout << "Введите " << count << " натуральных чисел:\n";
    for (int i = 0; i < count; i++) {
        cin >> num;
        if (num <= 0) {
            cout << "Только натуральные числа! Повторите ввод.\n";
            i--;
            continue;
        }
        numbers.push_back(num);
    }

    // ===== Сохранение всех чисел в numbers.txt =====
    ofstream numbersOut(numbersFile);
    if (!numbersOut.is_open()) {
        cout << "Ошибка создания файла numbers.txt!" << endl;
        return 1;
    }
    for (int n : numbers)
        numbersOut << n << " ";
    numbersOut.close();

    cout << "\nВсе числа сохранены в: " << numbersFile << endl;

    // ===== Выбор простых чисел =====
    vector<int> primes;
    for (int n : numbers) {
        if (isPrime(n))
            primes.push_back(n);
    }

    // ===== Сохранение простых чисел в primes.txt =====
    ofstream primesOut(primesFile);
    if (!primesOut.is_open()) {
        cout << "Ошибка создания файла primes.txt!" << endl;
        return 1;
    }
    for (int p : primes)
        primesOut << p << " ";
    primesOut.close();

    cout << "Простые числа сохранены в: " << primesFile << endl;
    cout << "Количество простых чисел: " << primes.size() << endl;

    // ===== Вычисление НОД =====
    int gcdAll = numbers[0];
    for (size_t i = 1; i < numbers.size(); i++)
        gcdAll = gcd(gcdAll, numbers[i]);

    cout << "НОД всех чисел: " << gcdAll << endl;

    // ===== Вычисление НОК =====
    long long lcmAll = numbers[0];
    for (size_t i = 1; i < numbers.size(); i++)
        lcmAll = lcm(lcmAll, numbers[i]);

    cout << "НОК всех чисел: " << lcmAll << endl;

    return 0;
}
