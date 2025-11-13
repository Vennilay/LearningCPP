#define _USE_MATH_DEFINES
#include <cmath>
#include <windows.h>
#include <iostream>
using namespace std;

void ex1_1();
void ex1_2();
void ex1_3();


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int num;
    do {
        system("cls");
        
        cout << "Введите фигуру"<<endl;
        cout << "1. Прямоугольник" << endl;
        cout << "2. Треуголтник" << endl;
        cout << "3. Круг" << endl;

        cin >> num;
        cout << endl;

        switch (num) {
        case 1: ex1_1(); break;
        case 2: ex1_2(); break;
        case 3: ex1_3(); break;
        case 0: cout << "Выход" << endl;
        default: cout << "Неверный выбор!" << endl;
        }
        
        if (num != 0) {
            cout << endl;
            system("pause");
        }
    
    } while (num != 0);

    return 0;

}


void ex1_1() {
    double a, b, s;
    cout << "Введите ширину" << endl;
    cin >> a;
    cout << "Введите высоту" << endl;
    cin >> b;
    s = a * b;
    cout << "Площадь прямоугольника: " << s << endl;
}
void ex1_2() {
    double a, b, s;
    cout << "Введите основание" << endl;
    cin >> a;
    cout << "Введите высоту" << endl;
    cin >> b;
    s = (a * b) / 2.0;
    cout << "Площадь треугольника: " << s << endl;

}
void ex1_3() {
    double r, s;
    cout << "Введите радиус";
    cin >> r;
    s = M_PI * pow(r, 2);
    cout << "Площадь круга: "<< s << endl;

}


