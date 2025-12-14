#include <iostream>

using namespace std;

int main() {
    long long n, m;

    cout << "Введите размер сетки N (строк) и M (столбцов): ";
    cin >> n >> m;

    long long countN = n * (n + 1) / 2;
    long long countM = m * (m + 1) / 2;

    cout << "Количество прямоугольников: " << countN * countM << endl;

    return 0;
}
