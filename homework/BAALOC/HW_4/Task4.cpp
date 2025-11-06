#include <iostream>
#include <iomanip>

int main() {
    int m1 = 37, i1 = 3, c1 = 64;
    int m2 = 25173, i2 = 13849, c2 = 65537;

    int howMany;
    std::cout << "Сколько чисел сгенерировать? ";
    std::cin >> howMany;

    auto seqA = new int[howMany];
    auto seqB = new int[howMany];
    seqA[0] = 0;
    seqB[0] = 0;

    std::cout << "\nГенерация для варианта A\n---------------------------------\n";
    for (int step = 0; step < howMany; ++step) {
        seqA[step] = (m1 * seqA[step - 1] + i1) % c1;
        std::cout << "Шаг " << step << ": " << seqA[step] << "\n";
        std::cout << "---------------------------------\n";
    }

    std::cout << "\nГенерация для варианта B\n---------------------------------\n";
    for (int step = 0; step < howMany; ++step) {
        seqB[step] = (m2 * seqB[step - 1] + i2) % c2;
        std::cout << "Шаг " << step << ": " << seqB[step] << "\n";
        std::cout << "---------------------------------\n";
    }

    delete[] seqA;
    delete[] seqB;
    return 0;
}
