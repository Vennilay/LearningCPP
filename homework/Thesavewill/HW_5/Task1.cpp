#include <iostream>
#include <map>
#include <string>
#include <windows.h>
using namespace std;
int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    string input; map<char, int> Map; int n, rez;
    Map['I'] = 1; Map['V'] = 2; Map['X'] = 3; Map['L'] = 4;
    Map['C'] = 5; Map['D'] = 6; Map['M'] = 7;
    for (int i = 0; i < 100;i++) {
        rez = 0;
        cout << "Введите римское число: ";cin >> input;
        for (int k = 0; k < input.length(); k++) {
            switch (Map[input[k]]) {
            case 1: n = 1; break; case 2: n = 5; break;
            case 3: n = 10; break; case 4: n = 50; break;
            case 5: n = 100; break; case 6: n = 500; break;
            case 7: n = 1000; break;
            default: n = 0; break;
            }
            if (Map[input[k]] < Map[input[k+1]]) {
                rez -= n;
            }
            else {
                rez += n;
            }
        }
        cout << "В арабских числах: " << rez << endl << endl;
    }
    return 0;
}