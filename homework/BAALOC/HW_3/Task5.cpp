#include <iostream>

bool isPrime(int n) {
    if (n == 2) {
        return true;
    }
    for (int i = 2; i <= std::sqrt(n) + 1; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 0;
    std::cout << "Введите число: ";
    std::cin >> n;

    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            std::cout << i << std::endl;
        }
    }
    return 0;
}
