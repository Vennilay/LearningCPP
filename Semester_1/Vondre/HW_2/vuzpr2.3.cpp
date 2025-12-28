#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Введите любое число: ";
    double n;
    cin >> n;
    int x = (int)n;
    if(n <= 0) {
        for(int i = 1; i < 11; i++) {
            cout << " " << i;
        }
    }
    else if(n * 10 != x * 10) {
        for(int i = x + 1; i < x + 11; i++) {
            cout << " " << i;
        }
    } else {
        cout << "Следующие за " << n << " натуральные числа: ";
        for(int i = n ; i < n + 10; i++) {
            cout << " " << i;
        }
    }

}