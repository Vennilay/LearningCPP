#include <iostream>
#include <cstring>

void delFirstMethod(char* x, int& n, char key, long long& comp, long long& moves) {
    comp = 0;
    moves = 0;

    int i = 0;
    while (i < n) {
        comp++;                 // сравнение x[i] с key
        if (x[i] == key) {
            // Сдвигаем влево включая '\0'
            for (int j = i; j < n; j++) {   // важно: j < n, чтобы скопировать '\0'
                x[j] = x[j + 1];
                moves++;
            }
            n--;
        } else {
            i++;
        }
    }
}

int main() {
    char x[256];
    std::cout << "Enter string: ";
    std::cin.getline(x, 256);

    char key;
    std::cout << "Enter char to delete: ";
    std::cin >> key;

    int n = (int)std::strlen(x); // длина без '\0'
    long long comp = 0, moves = 0;

    delFirstMethod(x, n, key, comp, moves);

    std::cout << "Result: " << x << "\n";
    std::cout << "n=" << n << " comp=" << comp << " moves=" << moves << "\n";
}