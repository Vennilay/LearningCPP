//2.1
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, x;
    cout << "Введите a и x:" << endl;
    cin >> a>>x;
    if (fabs(x) < 1.0) {
        if (fabs(x) <= 0) {
            cout << "Функция не определена" << endl;
        } else {
            cout << round(a * log(fabs(x))*100)/100<<endl;
        }
    } else {
        if (a - x * x < 0) {
            cout << "Функция не определена при данных значениях" << endl;
        }
        else {
            cout << "w = " << round(sqrt(a - x * x)*100)/100 << endl;
        }
    }

    return 0;
}