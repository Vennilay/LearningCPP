//3.4
#include <iostream>
using namespace std;
int nodvichet(int a, int b){
    while (a!=b) {
        if (a>b) {
            a=a-b;
        }else {
            b=b-a;
        }
    }
    return a;
}
int noddel(int a, int b) {
    while (b!=0) {
        int nod=b;
        b = a % b;  // остаток от деления
        a = nod;
    }
    return a;
}
int main() {
    int a,b,nod1,nod2;
    cin >>a >>b;
    if (a<0 && b<0) {
        cout<<"Числа должны быть положительными"<<endl;
    }else if (a==0 && b==0) {
        cout<<"Нод не определен"<< endl;
    }else {
        nod1=nodvichet(a,b);
        nod2=noddel(a,b);
        cout<<"НОД методом деления: "<<nod2<<endl;
        cout<<"НОД методом вычитания: "<<nod1<<endl;
    }
}