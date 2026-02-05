#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    string number;
    vector<int> numbers;
    ifstream inA, inB;
    ofstream out;

    inA.open("C:/Users/MXLNIK/Downloads/5.5.9_A.txt");
    inB.open("C:/Users/MXLNIK/Downloads/5.5.9_B.txt");
    out.open("C:/Users/MXLNIK/Downloads/5.5.9_C.txt");

    while (inA >> number)
    {
        numbers.emplace_back(stoi(number));
    }
    while (inB >> number)
    {
        numbers.emplace_back(stoi(number));
    }

    sort(numbers.begin(), numbers.end());
    for (int number : numbers)
    {
        out << number << " ";
    }

    inA.close();
    inB.close();
    out.close();

    return 0;
}
