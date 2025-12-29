#include <iostream>

using namespace std;

int main() {
    long long N, M;

    cout << "Введите количество N (строк): ";
    cin >> N;

    cout << "Введите количевство M (столбцов): ";
    cin >> M;

    long long count_N = N * (N + 1) / 2;
    long long count_M = M * (M + 1) / 2;

    cout << "Количество прямоугольников: " << count_N * count_M << endl;

    return 0;
}
