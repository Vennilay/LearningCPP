#include <iostream>
#include <windows.h> // Подключаем заголовок для функций Windows
using namespace std; // Используем пространство имен std

int main() {
    // Устанавливаем кодировку консоли на UTF-8 (только для Windows)
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    // Объявляем переменные N и M для размеров сетки
    long long N, M;

    // Считываем входные данные N и M из стандартного потока ввода
    cin >> N >> M;

    // Применяем формулу для расчета общего количества прямоугольников:
    // Количество = (N*(N+1)/2) * (M*(M+1)/2)
    long long totalRectangles = (N * (N + 1) / 2) * (M * (M + 1) / 2);

    // Выводим результат в стандартный поток вывода
    cout << totalRectangles << endl;

    return 0;
}
