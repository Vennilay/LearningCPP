#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    char replace_char, ch;
    ifstream in;
    ofstream out;

    cout << u8"Введите символ, на который будут заменены пробелы: ";
    cin >> replace_char;

    in.open("C:/Users/MXLNIK/Downloads/5.3.1_in.txt");
    out.open("C:/Users/MXLNIK/Downloads/5.3.1_out.txt");
    while (in.get(ch))
    {
        if (ch == ' ')
        {
            out.put(replace_char);
        }
        else
        {
            out.put(ch);
        }
    }
    in.close();
    out.close();

    return 0;
}
