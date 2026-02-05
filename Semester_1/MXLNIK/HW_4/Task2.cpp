#include <iostream>
using namespace std;

int main()
{
    string stars = "\r\033[44m * * * * * * * * ";
    string redline = "\033[41m                                          ";
    string whiteline = "\033[47m                                          ";

    for (int i = 0; i < 13; i++)
    {
        cout << (i % 2 == 0 ? redline : whiteline) << (i < 6 ? stars : "") << endl;
    }
    cout << "\033[0m";

    return 0;
}
