//3.2
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;
int main() {
    ifstream file("/Users/lkzz/CLionProjects/untitled/main.txt");
    if (!file) {
        cout<<"Файл не существует"<<endl;
        return 1;
    }
    char ch;
    bool isnumber = false;
    while (file.get(ch)) {
        if (isdigit(ch)) {
            cout << ch;
            isnumber=true;
        }else if (isnumber) {
            cout << " ";
            isnumber =false;
        }
    }
    file.close();
    return 0;
}