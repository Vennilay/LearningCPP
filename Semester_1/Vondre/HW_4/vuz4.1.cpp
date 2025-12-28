#include <iostream>

void pryamougolnik() {
    double shirina, height;
    std::cout<<"Введите ширину ";
    std::cin>>shirina;
    std::cout<<"Введите высоту ";
    std::cin>>height;
    if (height <= 0 or shirina <= 0) std::cout<<"Введено некорректное значение";
    else std::cout<<"Площадь прямоугольника равна "<<shirina*height<< std::endl;
}

void treugolnik() {
    double osnov, height;
    std::cout<<"Введите длину основания ";
    std::cin>>osnov;
    std::cout<<"Введите высоту ";
    std::cin>>height;
    if (height <= 0 or osnov <= 0) std::cout<<"Введено некорректное значение";
    else std::cout<<"Площадь треугольника равна "<<osnov * height * 0.5<< std::endl;
}

void krug() {
    double radius;
    std::cout<<"Введите рудиус ";
    std::cin>>radius;
    if (radius <= 0) std::cout<<"Введено некорректное значение";
    else std::cout<<"Площадь треугольника равна "<<radius*radius*3.1415926<< std::endl;
}

int main(){
    char again = 'y';
    while (again == 'y') {
        std::cout<<R"(Выберите, площадь какой фигуры вы хотите узнать?
1 - Прямоугольник
2 - Треугольник
3 - Круг)"<<std::endl;
        int vibor;
        std::cin>>vibor;
        switch (vibor) {
            case 1:
                pryamougolnik();
                break;
            case 2:
                treugolnik();
                break;
            case 3:
                krug();
                break;
        }

        std::cout<<"Хотите узнать площадь другой фигуры? y/n"<< std::endl;
        std::cin>>again;
    }
    std::cout<<"goodbye";
}