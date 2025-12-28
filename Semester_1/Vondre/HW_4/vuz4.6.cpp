#include <iostream>
#include <iomanip>

int main() {
    std::cout << "Выручка\tКомиссионные" << std::endl;
    double a[3][4]{
        {5, 2, 0, 10},
        {3, 5, 2, 5},
        {20, 0, 0, 0}
    };
    double b[4][2]{
        {1.2, 0.5},
        {2.8, 0.4},
        {5, 1},
        {2, 1.5}
    };
    double yach = 0, k = 0;
    double minvir = 1000, maxvir = 0, sellermaxvir, sellerminvir, obshvir = 0;
    double minkom = 1000, maxkom = 0, sellermaxkom, sellerminkom, obshkom = 0;
    double c[3][2]{0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            k+=1;
            for (int ab = 0; ab < 4; ab++) {
                yach += a[i][ab] * b[ab][j];
            }
            c[i][j] = yach;
            std::cout << std::setw(5) << yach << "\t  ";
            yach = 0;
        }
        std::cout << std::endl;
        //выручка
        if (c[i][0] > maxvir) {
            maxvir = std::max(maxvir, c[i][0]);
            sellermaxvir=i+1;
        }
        else if (c[i][0] < minvir) {
            minvir = std::min(minvir, c[i][0]);
            sellerminvir=i+1;
        }
        //комиссия
        if (c[i][1] > maxkom) {
            maxkom = std::max(maxkom, c[i][0]);
            sellermaxkom=i+1;
        }
        else if (c[i][1] < minkom) {
            minkom = std::min(minkom, c[i][0]);
            sellerminkom=i+1;
        }
        obshvir+=c[i][0];
        obshkom+=c[i][1];
    }
    std::cout << "Больше всего денег выручил продавец номер "<<sellermaxvir<<"; меньше всех продавец номер "<<sellerminvir<<std::endl;
    std::cout << "Больше всего комиссионных получил продавец номер "<<sellermaxkom<<"; меньше всех продавец номер "<<sellerminkom<<std::endl;
    std::cout<<"Общая выручка: "<<obshvir<<std::endl;
    std::cout<<"Общая комиссия: "<<obshkom<<std::endl;
    std::cout<<"Общая сумма денег прошедшая через продавцов: "<<obshkom+obshvir<<std::endl;
}