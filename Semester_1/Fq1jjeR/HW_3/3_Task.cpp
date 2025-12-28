#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>

using namespace std;

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    string line;

    bool allowed = true;

    cin >> line;
    for (int i = 0; i < line.length(); i++) {
        if (!(((line[i] > 64) && (line[i] <= 90)) || ((line[i] > 96) && (line[i] <= 122)) || (line[i] < 0))){
            allowed = false;
            break;
        }
    }

    if(allowed){
        line = line.substr(0, 30);
        sort(line.begin(), line.end());
        cout << line;

    }
    else{
        cout << "Error";
    }
    return 0;
}