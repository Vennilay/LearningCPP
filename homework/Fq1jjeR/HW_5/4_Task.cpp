#include <iostream>
#include <set>

using namespace std;

// === Задача 30 ===
// Подсчёт количества различных цифр в числе
int countUniqueDigits(string num) {
    set<char> digits;

    for (char c : num) {
        if (isdigit(c))
            digits.insert(c);
    }
    return digits.size();
}

// === Задача 31 ===
// Проверка наличия цифры 3 в квадрате double
bool containsThreeInSquare(double n) {
    double square = n * n;
    string s = to_string(square);
    return s.find('3') != string::npos;
}

// === Задача 32 ===
// Удаление цифр 0 и 5 из double
string removeZeroAndFive(string input) {
    string result;

    for (char c : input) {
        if (isdigit(c)&& (c != '0' && c != '5'))
            result += c;

        else if (c == '.' || c == '-')
            result += c;

    }

    // если удалили все цифры
    if (result == "-" || result == "." || result == "-." || result.empty())
        return "0";

    return result;
}


int main() {
    cout << "=== Задача 30 ===" << endl;
    cout << "Определение количества РАЗЛИЧНЫХ цифр в числе" << endl;

    string num;
    cout << "Введите число: ";
    cin >> num;
    cout << "Количество различных цифр: " << countUniqueDigits(num) << endl;



    cout << "\n=== Задача 31 ===" << endl;
    cout << "Проверка вхождения цифры 3 в квадрат числа" << endl;

    double n;
    cout << "Введите число n: ";
    cin >> n;
    cout << "n² = " << n * n << endl;

    if (containsThreeInSquare(n))
        cout << "Цифра 3 ВХОДИТ в запись числа n²" << endl;
    else
         cout << "Цифра 3 НЕ входит в запись числа n²" << endl;



    cout << "=== Задача 32 ===" << endl;
    cout << "Удаление цифр 0 и 5 из числа" << endl;

    string x;
    cout << "Введите число: ";
    cin >> x;
    cout << "После удаления 0 и 5: " << removeZeroAndFive(x) << endl;

    return 0;
}
