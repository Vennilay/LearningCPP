#include <iostream>
#include <cmath>
using namespace std;

main()
{
    cout<<"Введите основание логарифма: ";
    double osnov, arg;
    cin>>osnov;
    cout<< "Введите аргумент: ";
    cin>> arg;
    if (osnov == 1){
        cout<<"Основание не может быть равно 1";}
    else if (arg<0){
        cout<<"Аргумент должен быть больше или равен 0";
    }
    else{
        cout<< round(log(arg)/log(osnov));}
}