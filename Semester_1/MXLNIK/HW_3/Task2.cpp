#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    string line, all_lines, line_with_digits, result;
    string allowed = "1234567890 ";
    string number;
    ifstream fin;
    fin.open("C:\\Users\\MXLNIK\\Downloads\\text2.txt");
    while (getline(fin, line))
    {
        all_lines += line + " ";
    }
    fin.close();

    for (int i = 0; i < all_lines.length(); i++)
    {
        if (allowed.find(all_lines[i]) != string::npos)
        {
            line_with_digits += all_lines[i];
        }
        else
        {
            line_with_digits += " ";
        }
    }

    stringstream ss(line_with_digits);
    while (ss >> number)
    {
        result += number + " ";
    }

    if (result.empty())
    {
        cout << u8"В файле не обнаружены числа" << endl;
    }
    else
    {
        cout << result << endl;
    }
    return 0;
}
