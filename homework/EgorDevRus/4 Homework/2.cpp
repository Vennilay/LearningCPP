#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Былая слава 1912 года" << endl;
    cout << "Флаг США с 48 звездами и 13 полосами" << endl;

    for (int i=0; i < 8; i++) {
        cout << "\x1B[44m"<<endl;
        for (int star=0; star < 30; star++) {
            if (star < 8) {
                cout << "\x1B[37m* \x1B[44m";
            }
            else if (star > 8 && (i % 2 == 0)) {
                cout << "\x1B[41m \x1B[31m";
            }
            else if (star > 8 && ((i % 2) != 0)) {
                cout << "\x1B[47m \x1B[47m";
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        cout << endl;
        for (int j = 0; j < 37; j++) {
            if (i % 2 == 0) {
                cout << "\x1B[41m \x1B[31m";
            }
            else {
                cout << "\x1B[47m \x1B[47m";
            }
        }
    }
    cout << "\x1B[0m" << endl;
    
    
    
    
    
    return 0;
}