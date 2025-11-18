#include <iostream>

using namespace std;

double prymoygol(double shirina,double h) {
    cout<<"S = "<<shirina*h<<endl;
}
double treygol(double osnovanie,double h) {
    cout<<"S = "<<osnovanie*h*0.5<<endl;
}
double kryg(double r) {
    cout<<"S = "<<r*r*3.14<<endl;
}

int main() {
    double shirina, h, osnovanie, r;
    int vibor;
    cout<<R"(Площадь какой функции вы хотите узнать?
1-Площадь прямогольника
2-Площадь треуголника
3-Плоащадб круга
)";
    cin >> vibor;
    switch (vibor) {
        case 1:
            cout<<"Введите ширину и высоту для прямоугольника"<<endl;
            cin >> shirina >> h;
            prymoygol(shirina,h);
            break;
        case 2:
            cout<<"Введите основание и высоту для треугольника"<<endl;
            cin>>osnovanie >> h;
            treygol(osnovanie,h);
            break;
        case 3:
            cout<<"Введите радиус для круга"<<endl;
            cin >> r;
            kryg(r);
            break;
    }
    return 0;
}