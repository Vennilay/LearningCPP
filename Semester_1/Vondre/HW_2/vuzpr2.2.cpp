#include <iostream>
#include <cmath>
using namespace std;

main() {
    double x, y, b;
    cout << "Введите число x: ";
    cin >> x;
    cout << "Введите число y: ";
    cin >> y;
    cout << "Введите число b: ";
    cin >> b;
    if(b - x < 0) {
        cout << "Подкоренное выражение меньше 0";
    } else if(b - y <= 0) {
        cout << "Аргумент в линейной функции должен быть больше 0";
    } else {
        cout << "ln(b-y)*sqrt(b-x) = " << log(b - y)*pow(b - x, 0.5);
    }
}