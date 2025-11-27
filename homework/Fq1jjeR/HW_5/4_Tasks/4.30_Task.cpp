#include <iostream>
#include <set>

using namespace std;

int countUniqueDigits(string num) {
    set<char> digits;

    for (char c : num) {
        if (isdigit(c))
            digits.insert(c);
    }
    return digits.size();
}

int main() {
    cout << "Определение количества РАЗЛИЧНЫХ цифр в числе" << endl;

    string num;
    cout << "Введите число: ";
    cin >> num;
    cout << "Количество различных цифр: " << countUniqueDigits(num) << endl;

    return 0;
}