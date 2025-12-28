#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    double A[3][4] = {
            {5, 2, 0, 10},
            {3, 5, 2, 5},
            {20, 0, 0, 0}
    };

    double B[4][2] = {
            {1.20, 0.50},
            {2.80, 0.40},
            {5.00, 1.00},
            {2.00, 1.50}
    };

    double C[3][2] = {{0, 0},
                      {0, 0},
                      {0,0}};

    // Умножение матриц
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 4; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }


    cout << "Матрица C (выручка и комиссии):\n";
    for (int i = 0; i < 3; i++) {
        cout << "Продавец " << i + 1 << ": ";
        cout << "Выручка = " << C[i][0] << "   ";
        cout << "Комиссия = " << C[i][1] << endl;
    }


    int maxRevSeller = 0, minRevSeller = 0, maxComSeller = 0, minComSeller = 0;
    double totalRevenue = 0, totalCom = 0;

    for (int i = 0; i < 3; i++) {
        if (C[i][0] > C[maxRevSeller][0]) maxRevSeller = i;
        if (C[i][0] < C[minRevSeller][0]) minRevSeller = i;
        if (C[i][1] > C[maxComSeller][1]) maxComSeller = i;
        if (C[i][1] < C[minComSeller][1]) minComSeller = i;
        totalRevenue += C[i][0];
        totalCom += C[i][1];
    }

    cout << "\nБольше всего выручил продавец " << maxRevSeller + 1 << endl;
    cout << "Меньше всего выручил продавец " << minRevSeller + 1 <<endl;
    cout << "Больше всего комиссионных у продавца " << maxComSeller + 1 << endl;
    cout << "Меньше всего комиссионных у продавца " << minComSeller + 1 << endl;
    cout << "Общая выручка = " << totalRevenue <<endl;
    cout << "Общие комиссионные = " << totalCom << endl;
    cout << "Всего денег прошло через руки = " << totalRevenue + totalCom << endl;
    return 0;

}
