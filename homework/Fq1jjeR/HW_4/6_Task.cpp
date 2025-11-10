#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<double>> multiplyMatrices(const vector<vector<double>>& A,
                                        const vector<vector<double>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();

    vector<vector<double>> result(rowsA, vector<double>(colsB, 0.0));

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

int findMaxIndex(const vector<double>& vec) {
    int maxIndex = 0;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] > vec[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int findMinIndex(const vector<double>& vec) {
    int minIndex = 0;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] < vec[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    // Матрица A: количество проданных товаров (3 продавца × 4 товара)
    vector<vector<double>> A = {
            {5, 2, 0, 10},  // Продавец 1
            {3, 5, 2, 5},   // Продавец 2
            {20, 0, 0, 4}   // Продавец 3
    };

    // Матрица B: (цена, комиссионные) для 4 товаров
    vector<vector<double>> B = {
            {1.20, 0.50},   // Товар 1
            {2.80, 0.40},   // Товар 2
            {5.00, 1.00},   // Товар 3
            {2.00, 1.50}    // Товар 4
    };

    // Умножаем матрицы: C = A × B
    vector<vector<double>> C = multiplyMatrices(A, B);

    cout << fixed << setprecision(2);
    cout << "Матрица C (продавцы × (выручка, комиссионные)):\n";
    for (int i = 0; i < C.size(); i++) {
        cout << "Продавец " << (i + 1) << ": "
             << "Выручка = " << setw(6) << C[i][0]
             << ", Комиссионные = " << setw(6) << C[i][1] << endl;
    }

    // Сбор данных
    vector<double> revenue, commissions;
    for (auto &row : C) {
        revenue.push_back(row[0]);
        commissions.push_back(row[1]);
    }

    // Находим максимум и минимум
    int maxRev = findMaxIndex(revenue);
    int minRev = findMinIndex(revenue);
    int maxComm = findMaxIndex(commissions);
    int minComm = findMinIndex(commissions);

    // Считаем суммы
    double totalRev = 0, totalComm = 0;
    for (double r : revenue) totalRev += r;
    for (double c : commissions) totalComm += c;
    double totalMoney = totalRev + totalComm;

    // Вывод результатов
    cout << "\nОтветы на вопросы:\n";
    cout << "1) Больше всего выручил: продавец " << (maxRev + 1)
         << ", меньше всего: продавец " << (minRev + 1) << endl;
    cout << "2) Наибольшие комиссионные: продавец " << (maxComm + 1)
         << ", наименьшие: продавец " << (minComm + 1) << endl;
    cout << "3) Общая выручка: " << totalRev << endl;
    cout << "4) Всего комиссионных: " << totalComm << endl;
    cout << "5) Общая сумма денег (выручка + комиссионные): " << totalMoney << endl;

    return 0;
}
