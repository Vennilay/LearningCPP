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
    cout << "Введите ежемесячную выплату по кредиту: ";
    int m;
    cin >> m;
    for(double r = -1; r < 1; r += 0.0001) {
        if(r != 0 and abs((S * r * pow((1 + r), n)) / (12 * ((pow(1 + r, n) - 1))) - m) < 1.0) {
            cout << "Ставка по кредиту равна " << r * 100 << "%";
            break;
        }

    }
}
