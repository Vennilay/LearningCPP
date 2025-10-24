#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Введите сумму вашего кредита: ";
    int S;
    cin >> S;
    cout << "Введите срок кредита в годах: ";
    int n;
    cin >> n;
    cout << "Введите ставку по кредиту: ";
    double p;
    cin >> p;
    // double r = p / 100 / 12;
    double r = p / 100.0;
    if(r == 0) {
        cout << "Размер месячной выплаты равен " << S / n / 12;
    } else {
        cout << "Размер месячной выплаты равен " << (S * r * pow((1 + r), n)) / (12 * ((pow(1 + r, n) - 1))) << " рублей";
    }
    // cout << "Размер месячной выплаты равен " << (S * r * pow((1 + r), n*12)) / (((pow(1 + r, n*12) - 1))) << " рублей";
}