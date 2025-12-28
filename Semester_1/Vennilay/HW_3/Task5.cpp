#include <iostream>
#include <vector>

int main() {
    int n = 0;
    std::cout << "Введите натуральное число n: ";
    std::cin >> n;

    if (n < 2) {
        std::cout << "Простых чисел нет." << std::endl;
        return 1;
    }

    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    std::cout << "Простые числа от 2 до " << n << ": ";
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i])
            std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
