#include <iostream>

int main() {
    double A[3][4] = {
        {5, 2, 0, 10},
        {3, 5, 2, 5},
        {20, 0, 0, 0}
    };

    double B[4][2] = {
        {1.2, 0.5},
        {2.8, 0.4},
        {5.0, 1.0},
        {2.0, 1.5}
    };

    double C[3][2] = {0};

    std::cout << "=== МАТРИЦЫ ===\n\n";

    for (int prodavec = 0; prodavec < 3; prodavec++) {
        for (int stolbec = 0; stolbec < 2; stolbec++) {
            std::cout << "Считаем C[" << prodavec << "][" << stolbec << "] ";
            std::cout << "(Продавец " << prodavec + 1 << ", ";
            std::cout << (stolbec == 0 ? "Выручка" : "Комиссионные") << "):\n";

            for (int tovar = 0; tovar < 4; tovar++) {
                double proizvedinije = A[prodavec][tovar] * B[tovar][stolbec];
                C[prodavec][stolbec] += proizvedinije;

                std::cout << "  Товар " << tovar + 1 << ": A[" << prodavec << "][" << tovar << "] * B["
                         << tovar << "][" << stolbec << "] = "
                         << A[prodavec][tovar] << " * " << B[tovar][stolbec]
                         << " = " << proizvedinije
                         << " | Накопленная сумма: " << C[prodavec][stolbec] << "\n";
            }
            std::cout << "  ИТОГО: C[" << prodavec << "][" << stolbec << "] = "
                     << C[prodavec][stolbec] << "\n\n";
        }
    }

    std::cout << "\n=== ИТОГОВАЯ МАТРИЦА C ===\n\n";
    std::cout << "          Выручка    Комиссионные\n";
    std::cout << "        +-----------+-------------+\n";
    for (int prodavec = 0; prodavec < 3; prodavec++) {
        std::cout << "Продавец " << prodavec + 1 << " |  "
                 << C[prodavec][0] << "  |    "
                 << C[prodavec][1] << "    |\n";
    }
    std::cout << "        +-----------+-------------+\n\n";

    int maxRev = 0, minRev = 0, maxCom = 0, minCom = 0;
    double obshayaVyruchka = 0, obshieKomissionnie = 0;

    for (int prodavec = 0; prodavec < 3; prodavec++) {
        if (C[prodavec][0] > C[maxRev][0]) maxRev = prodavec;
        if (C[prodavec][0] < C[minRev][0]) minRev = prodavec;
        if (C[prodavec][1] > C[maxCom][1]) maxCom = prodavec;
        if (C[prodavec][1] < C[minCom][1]) minCom = prodavec;
        obshayaVyruchka += C[prodavec][0];
        obshieKomissionnie += C[prodavec][1];
    }

    std::cout << "Больше всего выручил продавец " << maxRev + 1 << "\n";
    std::cout << "Меньше всего выручил продавец " << minRev + 1 << "\n";
    std::cout << "Больше всего комиссионных у продавца " << maxCom + 1 << "\n";
    std::cout << "Меньше всего комиссионных у продавца " << minCom + 1 << "\n";
    std::cout << "Общая выручка = " << obshayaVyruchka << "\n";
    std::cout << "Общие комиссионные = " << obshieKomissionnie << "\n";
    std::cout << "Всего денег прошло через руки = " << obshayaVyruchka + obshieKomissionnie << "\n";
    return 0;
}