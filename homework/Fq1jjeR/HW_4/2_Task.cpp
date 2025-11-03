#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void drawFlag() {
    cout << "┌─────────────────────────────────────────────────────────┐" << endl;

    // Верхняя часть с звездами и полосами
    for (int row = 0; row < 6; row++) {
        cout << "│ ";
        // Звезды (6 рядов)
        for (int star = 0; star < 8; star++) {
            cout << " ";
        }
        cout << " │ ";
        // Полосы
        for (int stripe = 0; stripe < 7; stripe++) {
            cout << "█";
        }
        cout << " │" << endl;
    }

    // Нижняя часть только с полосами
    for (int row = 0; row < 7; row++) {
        cout << "│                     │ ";
        for (int stripe = 0; stripe < 7; stripe++) {
            if (row % 2 == 0) {
                cout << "█";
            } else {
                cout << " ";
            }
        }
        cout << " │" << endl;
    }

    cout << "└─────────────────────────────────────────────────────────┘" << endl;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    cout << "Флаг 'Былая слава' 1912 года" << endl;
    cout << "=============================" << endl;
    cout << endl;

    drawFlag();

    cout << endl;
    cout << "Характеристики флага:" << endl;
    cout << "- 48 звезд (по количеству штатов в 1912 году)" << endl;
    cout << "- 13 полос (по количеству первоначальных колоний)" << endl;
    cout << "- Соотношение сторон: 10:19" << endl;

    return 0;
}