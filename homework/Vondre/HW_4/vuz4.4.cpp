// #include <iostream>
// int gen (int i, int m, int c) {
//     if (i==0) {
//         return  1;
//     }
//     else {
//         return (m*gen(i-1, m, c))%c;
//     }
// }
// int main() {
//     char again='y';
//     while (again == 'y') {
//         int m, i, c;
//         std::cout<<"Введите значение чиcла m: ";
//         std::cin>>m;
//         std::cout<<"Введите значение числа i: ";
//         std::cin>>i;
//         std::cout<<"Введите значение числа c: ";
//         std::cin>>c;
//         std::cout<<gen(i, m, c)<<std::endl;
//
//         std::cout<<"Еще разок?y/n ";
//         std::cin>>again;
//     }
// }

#include <iostream>

int gen(int i, int m, int c) {
    if (i == 0) return 1;
    int prev = gen(i - 1, m, c);
    return (m * prev) % c;
}

int main() {
    char again='y';
    while (again == 'y') {
        int m, c, count;
        std::cout << "Введите значение m: ";
        std::cin >> m;
        std::cout << "Сколько чисел сгенерировать? ";
        std::cin >> count;
        std::cout << "Введите значение c: ";
        std::cin >> c;

        for (int i = 0; i < count; ++i) {
            std::cout << gen(i, m, c) << " ";
        }
        std::cout << "\n";

        std::cout<<"Еще разок?y/n ";
        std::cin>>again;
    }
    return 0;
}
