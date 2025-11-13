#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const char spinner[] = "|/-\\";

    for (int i = 0; i < 30; ++i) {                                 // \r переносит курсор консоли в начало и пишет заново строку заменяя символы,
        cout << "\r" << spinner[i % 4] << " Загрузка...";          // если недостаточно места для новой строки.
        Sleep(100);                                                // Sleep(x) - заставляет систему ждать X мс.
    }
    cout << "\rГотово, вы натурал!";                               // Копиум
}