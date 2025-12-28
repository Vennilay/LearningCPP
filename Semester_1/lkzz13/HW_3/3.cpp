//3.3
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;
int main() {
    ifstream file("/Users/lkzz/CLionProjects/untitled/main.txt");
    if (!file) {
        cout << "Файл не обнаружен"<<endl;
        return 1;
    }
    stringstream f;
    f << file.rdbuf();
    string line = f.str();
    if (line.empty()) {
        cout<<"Файл пуст"<<endl;
    }else {
        sort(line.begin(),line.end());
        cout<<line<<endl;
    }
    return 0;
}