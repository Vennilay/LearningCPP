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

    // Генерация по возрастанию (1, 2, 3... 1 000 000)
    for (int i = 1; i <= n; i++) {
        outFile << i << " ";
    }

    outFile.close();
    cout << "Файл numbers_best.txt создан (лучший случай: отсортирован по возрастанию)." << endl;

    return 0;
}
