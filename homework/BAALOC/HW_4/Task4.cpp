#include <iostream>

int generatePassword(int c, int i, int m, int n, int s) {
    std::cout << s << std::endl;
    if (n == 0) {
        return s;
    }
    n--;
    s = (m * generatePassword(c, i, m, n, s) + i) % c;
    return s;
}

int main() {
    int c = 64, i = 3, m = 37, n = 0;
    n = 10;

    int password = generatePassword(c, i, m, n, 0);
    std::cout << password << std::endl;
}
