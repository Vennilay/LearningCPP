#include <iostream>

int main() {
    int a = 0, b = 0;
    std::cout << "Введите первое число: ";
    std::cin >> a;
    std::cout << "Введите второе число: ";
    std::cin >> b;
    int m = a, n = b;
    //деление
    while (a != 0 and b != 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    std::cout << "НОД подсчитанный алгоритмом евклида равен " << (a + b)<<std::endl;

    //Метод поиска НОД через вычитание
    while (m != n) {
        if (m > n) {
            m = m - n;
        } else {
            n = n - m;
        }
    }
    std::cout<<"НОД подсчитанный с помощью вычитания равен "<<m;
}
