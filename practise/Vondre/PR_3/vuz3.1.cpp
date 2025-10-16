#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    cout << "Введите вещественное число: ";
    string vvod;
    cin >> vvod;
    string proverka = vvod;
    reverse(vvod.begin(), vvod.end());
    if(proverka == vvod) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
