#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const int n = 1000000;
    ofstream outFile("numbers.txt");

    if (!outFile.is_open()) {
        cerr << "Ошибка создания файла!" << endl;
        return 1;
    }

    for (int i = n; i > 0; i--) {
        outFile << i << " ";
    }

    outFile.close();
    cout << "Файл numbers.txt успешно создан (1 млн чисел, худший случай)." << endl;

    return 0;
}
