#include <iostream>
#include <cmath>
#include <set>
#include <string>

// 2
double task2(int n) {
    double y = 0.0;
    int start = 1;

    for (int k = 0; k < n; ++k) {
        unsigned long long fact = 1;

        for (int j = n - k; j >= 1; --j) {
            fact *= j;
        }

        int sum = 0;
        int count = k + 1;

        for (int j = 0; j < count; ++j) {
            sum += start + j;
        }

        y += static_cast<double>(fact) / std::sqrt(sum);

        start += count;
    }

    return y;
}

// 4
double task4(int n) {
    double y = 0.0;

    for (int k = 1; k <= n; ++k) {
        unsigned long long factorial = 1;

        for (int i = 1; i <= k; ++i) {
            factorial *= i;
        }

        double sum = 0.0;

        for (int i = 1; i <= k; ++i) {
            sum += 1.0 / i;
        }

        y += static_cast<double>(factorial) / sum;
    }

    return y;
}

// 30
size_t task30(long long n) {
    std::set<char> digits;
    std::string s = std::to_string(std::llabs(n));
    for (char c : s) {
        digits.insert(c);
    }
    return digits.size();
}


int main() {
    int n2, n4;
    std::cout << "Введите n для второй задачи: ";
    std::cin >> n2;

    double result2 = task2(n2);
    std::cout << "Ответ для второй задачи: " << result2 << std::endl;

    std::cout << "Введите n для четвертой задачи: ";
    std::cin >> n4;

    double result4 = task4(n4);
    std::cout << "Ответ для четвертой задачи: " << result4 << std::endl;

    long long num;
    std::cout << "Введите целое число для анализа цифр: ";
    std::cin >> num;

    std::cout << "Количество различных цифр: " << task30(num) << std::endl;

    return 0;
}
