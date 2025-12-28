//3.1
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int main() {
    ifstream file("/Users/lkzz/CLionProjects/untitled/main.txt");
    if(!file) {
        cout<<"Файл не существует" <<endl;
        return 1;
    }
    stringstream f;
    f << file.rdbuf();
    string content = f.str();
    if (content.empty()) {
        cout<<"Файл пуст"<<endl;
    }else {
        cout<<content<<endl;
    }
    return 0;
}