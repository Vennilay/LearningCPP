#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> qty = {
            {5, 2, 0, 10},
            {3, 5, 2, 5},
            {20, 0, 0, 0}
        };

    std::vector<std::vector<double>> props = {
            {1.2, 0.5},
            {2.8, 0.4},
            {5.0, 1.0},
            {2.0, 1.5}
        };

    std::vector<std::vector<double>> results(3, std::vector<double>(2, 0.0));
    for (int seller = 0; seller < 3; ++seller)
        for (int field = 0; field < 2; ++field)
            for (int item = 0; item < 4; ++item)
                results[seller][field] += qty[seller][item] * props[item][field];

    for (int i = 0; i < 3; ++i) {
        std::cout << "Продавец " << (i + 1) << "\n";
        std::cout << "Выручка: " << results[i][0] << "\n";
        std::cout << "Комиссионные: " << results[i][1] << "\n";
        std::cout << "-------------------------------\n";
    }

    int rev_max = 0, rev_min = 0, comm_max = 0, comm_min = 0;
    double sum_revenue = 0, sum_comm = 0;
    for (int i = 0; i < 3; ++i) {
        if (results[i][0] > results[rev_max][0]) rev_max = i;
        if (results[i][0] < results[rev_min][0]) rev_min = i;
        if (results[i][1] > results[comm_max][1]) comm_max = i;
        if (results[i][1] < results[comm_min][1]) comm_min = i;
        sum_revenue += results[i][0];
        sum_comm += results[i][1];
    }

    std::cout << "Больше всего выручил продавец: " << (rev_max + 1) << "\n";
    std::cout << "Меньше всего выручил продавец: " << (rev_min + 1) << "\n";
    std::cout << "Максимум комиссионных: " << (comm_max + 1) << "\n";
    std::cout << "Минимум комиссионных: " << (comm_min + 1) << "\n";
    std::cout << "Общая выручка: " << sum_revenue << "\n";
    std::cout << "Общая сумма комиссионных: " << sum_comm << "\n";
    std::cout << "Всего денег прошло через руки: " << sum_revenue + sum_comm << "\n";
    return 0;
}
