#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ofstream file("/Users/lkzz/CLionProjects/untitled/main.txt");

    if (file.is_open()) {
        file << "Hello World!";
        cout << "Запись прошла успешно" << endl;
        file.close();
    } else {
        cout << "Не удалось записать текст в файл" << endl;
    }
    return 0;
}