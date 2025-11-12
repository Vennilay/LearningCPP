#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float number1; float number2;
    cout << "Введите первое число: "; cin >> number1;
    cout << "Введите второе число: "; cin >> number2;
    float summ = number1 + number2;
    float raz = number1 - number2;
    float proiz = number1 * number2;
    cout << "Сумма: " << summ << endl << "Разность: " << abs(raz) << endl << "Произведение: " << proiz << endl;
    if (number2 != 0) {
        float chast = number1 / number2;
        cout << "Частное от деления первого числа на второе: " << chast;
    }
    else if (number1 != 0) {
        float chast = number2 / number1;
        cout << "Частное от деления второго числа на первое: " << chast;
    }
    else{
        cout << "Получить частное от деления нельзя";
    }
    return 0;
}