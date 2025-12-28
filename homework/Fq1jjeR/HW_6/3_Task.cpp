#include <iostream>

using namespace std;

int main() {
    int N, M;

    cout << "Введите количество N (строк): ";
    cin >> N;

    cout << "Введите количевство M (столбцов): ";
    cin >> M;

    int count_N = N * (N + 1) / 2;
    int count_M = M * (M + 1) / 2;

    cout << "Количество прямоугольников: " << count_N * count_M << endl;

    return 0;
}
