#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Матрица A - количество товаров
    vector<vector<int>> A = {
        {5, 3, 2, 8},  // Продавец 1
        {4, 6, 1, 5},  // Продавец 2
        {7, 2, 4, 3}   // Продавец 3
    };

    // Матрица B - цены и комиссионные
    vector<vector<double>> B = {
        {1.20, 0.50},  // Товар 1
        {2.80, 0.40},  // Товар 2
        {5.00, 1.00},  // Товар 3
        {2.00, 1.50}   // Товар 4
    };

    // Результирующая матрица C
    vector<vector<double>> C(3, vector<double>(2, 0));

    // Умножение матриц
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 4; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Анализ результатов
    cout << "Результаты:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Продавец " << i+1 << ": Выручка=" << C[i][0]
             << ", Комиссионные=" << C[i][1] << endl;
    }

    return 0;
}