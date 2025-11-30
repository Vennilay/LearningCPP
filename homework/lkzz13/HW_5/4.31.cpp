#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введите целое число n: ";
    cin >> n;

    int n2 = n * n;
    bool usedThree = false;

    if (n2 == 0) {
        usedThree = false;
    } else {
        int temp = n2;
        while (temp > 0) {
            int digit = temp % 10;
            if (digit == 3) {
                usedThree = true;
                break;
            }
            temp /= 10;
        }
    }
    cout<<"n^2 = "<<n2<<endl;
    if (usedThree) {
        cout << "Цифра 3 входит в запись n^2" << endl;
    } else {
        cout << "Цифра 3 не входит в запись n^2" << endl;
    }
    return 0;
}