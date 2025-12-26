#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    int a, b ,c, cost = 0, n = 0 , remember = 0, ans = 0;
    cout << "Введите a:"; cin >> a;
    cout << "Введите b:"; cin >> b;
    cout << "Введите c:"; cin >> c;

    while (cost < c) {
        ++n;
        cost = a + b * n;
        if (cost > c && remember != 0) {
            ans = remember;
        }
        else if (cost > c && remember == 0){
            ans = remember;;
        }
        remember = n;
    }
    cout << "Ответ:" << ans;
    return 0;
}