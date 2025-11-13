#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a, b;
  
    
    
    // 1 способ делением
    cout << "Введите первое число(a): ";
    cin >> a;

    cout << "Введите второе число(b): ";
    cin >> b;

    while (a != 0 && b != 0) {
        if (a > b) a %= b;
        else b %= a;
    }

    int res = a + b;
    cout << "наибольший общий делитель(делением): " << res<<endl;

    
    //2 способ вычитанием

    int M, N;
    cout << "Введите первое число(M): ";
    cin >> M;
    cout << "Введите второе число(N): ";
    cin >> N;

    while (M != N) {
        if (M > N) M -= N;
        else N -= M;
    }
    cout <<"наибольший общий делитель(вычитанием): " << M;






    return 0;
}
