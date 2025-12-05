#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;
double roundToSixDecimalPlaces(double value) {
    // 1. Умножаем число на 1,000,000 (10^6).
    double scaled_value = value * 1000000.0;

    // 2. Округляем до ближайшего целого числа, используя std::round.
    // std::round использует стандартные правила округления (к ближайшему целому).
    double rounded_scaled_value = std::round(scaled_value);

    // 3. Делим обратно на 1,000,000.0, чтобы получить 6 знаков после запятой.
    double result = rounded_scaled_value / 1000000.0;

    return result;
}

long long Factorial(int n) {
    if (n < 0) {
        std::cerr << "Ошибка: Факториал отрицательного числа не существует." << std::endl;
        return -1;
    }

    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}
//15
int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    int k;
    double x, y = 0.0;

    cout << "Введите X:";
    cin >> x;

    for (k = 0; k < 100; ++k) {
        double term = Factorial((2 * k + 1)) / pow((k + 1), 2) * pow(x, 4.0 * k);
        y += term;
    }

    cout << roundToSixDecimalPlaces(y);
    return 0;
}