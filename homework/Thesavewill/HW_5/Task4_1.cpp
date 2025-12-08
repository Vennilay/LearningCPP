#include <iostream>
#include <windows.h> // Для SetConsoleCP и SetConsoleOutputCP
using namespace std;
//8
int main() {
    // Устанавливаем кодировку консоли Windows в UTF-8
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    double a;
    int n;
    cout << "Введите a:"; cin >> a;
    cout << "Введите n:"; cin >> n;

    double y = 0.0;
    double denominator = a; // Начнем с первого члена: a

    for (int i = 0; i <= n; ++i) {
        // Добавляем текущий член (i+1)/denominator
        y += (i + 1) / denominator;

        // Умножаем denominator на следующий множитель для следующей итерации
        denominator *= (a + i + 1);
    }

    cout << "Сумма y = " << y << endl;
    return 0;
}
