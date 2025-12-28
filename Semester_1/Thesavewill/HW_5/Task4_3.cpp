#include <iostream>
#include <windows.h>
using namespace std;

int CommonDivisor(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
//61
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int input= 5;
    cout << "Размер массива: " << input;
    cout << "Введите значения массива:";

    int numbers[input];
    for (int k = 0; k < input; k++) {
        cin >> numbers[k];
    }

    int MaxCD = numbers[0];
    for (int i = 1; i < input; i++) {
        MaxCD = CommonDivisor(MaxCD, numbers[i]);
    }

    int MinCD = MaxCD;
    for (int d = 1; d <= MaxCD; d++) {
        if (MaxCD % d == 0) {
            MinCD = d;
            break;
        }
    }

    cout << "Наименьший общий делитель: " << MinCD << endl;
    cout << "Наибольший общий делитель: " << MaxCD << endl;

    return 0;
}
