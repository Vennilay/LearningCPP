#include <cmath>
#include<windows.h>
#include<string>
#include <iostream>
using namespace std;
void ex1();
void ex2();
void ex3();
void ex4();
void ex5();
void ex6();

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int ex;
    do {
        cout<< endl; cout << endl;
        system("cls");
        cout << "Выберите задание" << endl;
        cout << "1. Разветвление" << endl;
        cout << "2. Функция" << endl;
        cout << "3. Порядок" << endl;
        cout << "4. Табуляция" << endl;
        cout << "5. Заем" << endl;
        cout << "6. Ссуда" << endl;
        cout << "0. Выход" << endl;
        cin >> ex;

        cout<< endl;
        switch (ex) {
        case 1: ex1(); break; 
        case 2: ex2(); break; 
        case 3: ex3(); break; 
        case 4: ex4(); break; 
        case 5: ex5(); break; 
        case 6: ex6(); break; 
        case 0: cout << "Выход" << endl; break;
        default: cout << "Неверный выбор!" << endl;
        }

        if (ex != 0) {
            cout << endl;
            system("pause");
        }

    } while (ex != 0);
    return 0;
}


void ex1()
{
    float x, a, w;
    cout << "Введите x: "; cin >> x;
    cout << "Введите a: "; cin >> a;
    if (abs(x) < 1)
        if (x != 0) {
            w = a * log(abs(x));
            cout << w;
        }
        else {

            cout << "Нет решений";
        }
    if (abs(x) >= 1) {
        if ((a - pow(x, 2) >= 0)) {
            w = sqrt(a - pow(x, 2));
            cout << w;
        }
        else {

            cout << "Нет решений";
        }
    }

    

}
void ex2()
{
    float b, x, y, z;

    cout << "Введите b: "; cin >> b;
    cout << "Введите x: "; cin >> x;
    cout << "Введите y: "; cin >> y;

    if (b - y > 0 && b - x >= 0) {
        z = log(b - y) * sqrt(b - x);
        cout << z;
    }
    else
        cout << "Нет решений";
}
void ex3() {
    // отриц дробные
    double x;
    int i = 0;

    cout << "Введите число: "; cin >> x;
    for (x; i < 10; x++) {
        if (x > 0) {
            x=ceil(x);
            i ++;
            cout << x << endl;
        }
        else {
            x = 0;
        }
    }
}
void ex4()
{
    float y;
    /*for (float x = -4; x <= 4; x += 0.5)
        if ((x - 1) == 0) {
            cout << "x: " << x << " " << "y: Деление на ноль" << endl;
        }
        else {
            y = (pow(x, 2) - 2 * x + 2) / (x - 1);
            cout << "x: " << x<<" "<< "y: " << y<<endl;
        }*/
    float x = -4;

    while (x <= 4) {
        if ((x - 1) == 0) {
            cout << "x: " << x << " " << "y: Деление на ноль" << endl;
        }
        else {
            y = (pow(x, 2) - 2 * x + 2) / (x - 1);
            cout << "x: " << x << " " << "y: " << y << endl;
        }
        x += 0.5;
    }

}
void ex5() {
    
    int n;
    double r, m, S, p;
    cout << "Введите сумму займа: "; cin >> S;
    cout << "Введите процент: "; cin >> p;
    cout << "Введите на сколько лет: "; cin >> n;
    //для нуля доделать
    if (p == 0) {
        m = S / (12 * n);
        cout << m;
    }
    else if (n >= 1 && S > 0 && p != (-1)) {

        r = p / 100.0;

        m = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
        cout << "Месячная выплата: " << m << endl;
        cout << "Срок займа в годах: " << n << endl;
    }
    else {
        cout << "Некорректные данные" << endl;
    }
}
void ex6() {
    int n;
    double r, m, S, p, m1, delta, min_delta, best_p;

    cout << "Введите сумму займа: "; cin >> S;
    cout << "Введите на сколько лет: "; cin >> n;
    cout << "Введите месячную выплату: "; cin >> m;

    best_p = 0;
    min_delta = 10000;


    if (n >= 1 && S > 0) {
        for (int p = 0; p <= 100; p++) {
            r = p / 100.0;
            m1 = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
            delta = abs(m1 - m);
            if (delta < min_delta) {
                min_delta = delta;
                best_p = p;


            }
        }
        cout << "Процентная ставка: " << best_p << endl;
    }
    else {
        cout << "Некорректные данные" << endl;
    }

}