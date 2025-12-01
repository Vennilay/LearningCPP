#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    string BASE_PATH = "D:\\Coding\\LearningCPP\\files\\Fq1jjeR\\HW_5\\";
    string numbersFile = BASE_PATH + "numbers.txt";
    string primesFile = BASE_PATH + "primes.txt";

    int count;
    cout << "Сколько натуральных чисел хотите ввести: ";
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

    // Сохранение всех чисел
    ofstream numbersOut(numbersFile);
    for (int n : numbers)
        numbersOut << n << " ";
    numbersOut.close();

    // Выбор простых чисел
    vector<int> primes;
    for (int n : numbers) {
        if (isPrime(n))
            primes.push_back(n);
    }

    // Сохранение простых чисел
    ofstream primesOut(primesFile);
    for (int p : primes)
        primesOut << p << " ";
    primesOut.close();

    cout << "Количество простых чисел: " << primes.size() << endl;

    // Вычисление НОД
    int gcdAll = numbers[0];
    for (size_t i = 1; i < numbers.size(); i++)
        gcdAll = gcd(gcdAll, numbers[i]);

    cout << "НОД всех чисел: " << gcdAll << endl;

    // Вычисление НОК
    int lcmAll = numbers[0];
    for (size_t i = 1; i < numbers.size(); i++)
        lcmAll = lcm(lcmAll, numbers[i]);

    cout << "НОК всех чисел: " << lcmAll << endl;

    return 0;
}