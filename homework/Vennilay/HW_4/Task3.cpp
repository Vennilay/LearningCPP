#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int size = 100;   // ширина графика
    int height = 21;  // высота
    int axisX = 3;    // отступ для оси Y (слева)

    vector<string> sinGraph(height, string(size + axisX, ' ')); // пустое поле с отступом

    // Рисуем ось Y
    for(int i = 0; i < height; i++) {
        sinGraph[i][axisX] = '|';
    }

    // Ось X
    for(int i = axisX; i < size + axisX; i++) {
        sinGraph[height/2][i] = '-';
    }

    // Пересечение осей
    sinGraph[height/2][axisX] = '+';

    // Подписи оси Y
    sinGraph[0][axisX - 1] = '1';      // y = 1
    sinGraph[height/2][axisX - 1] = '0'; // y = 0
    sinGraph[height - 1][axisX - 1] = '-'; // начало для y = -1
    sinGraph[height - 1][axisX - 2] = '1'; // y = -1

    // Точки графика
    for(int i = 0; i < size; i++) {
        sinGraph[(round(10 * sin(i / 4.5) + 10))][i + axisX] = '*';
    }

    // Напечатать
    for(auto s: sinGraph) {
        cout << s << '\n';
    }
}
