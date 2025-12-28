#include <iostream>

using namespace std;

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
    cout << "Удаление цифр 0 и 5 из числа" << endl;

    string x;
    cout << "Введите число: ";
    cin >> x;
    cout << "После удаления: " << removeZeroAndFive(x) << endl;

    return 0;
}