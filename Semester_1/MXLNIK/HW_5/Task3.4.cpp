#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    ifstream in;
    string word, longest_word = "";

    in.open("C:/Users/MXLNIK/Downloads/5.3.4.txt");
    while (in >> word)
    {
        if (word.length() > longest_word.length())
        {
            longest_word = word;
        }
    }
    in.close();

    cout << u8"Самое длинное слово: " << longest_word << endl;

    return 0;
}
