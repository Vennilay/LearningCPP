#include <iostream>

using namespace std;

// Проверка наличия цифры 3 в квадрате double
bool containsThreeInSquare(double n) {
    double square = n * n;
    string s = to_string(square);
    return s.find('3') != s.npos;
}

int main() {
    cout << "Проверка вхождения цифры 3 в квадрат числа" << endl;

    double n;
    cout << "Введите число n: ";
    cin >> n;
    cout << "n² = " << n * n << endl;

    if (containsThreeInSquare(n))
        cout << "Цифра 3 ВХОДИТ в запись числа n²" << endl;
    else
        cout << "Цифра 3 НЕ входит в запись числа n²" << endl;

    return 0;
}