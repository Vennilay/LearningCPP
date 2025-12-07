#include <iostream>
#include <cmath>

int main() {
    long long n;

    std::cout << "Введите целое число: ";
    std::cin >> n;

    n = std::abs(n);

    int seen[10] = {0};

    if (n == 0) {
        seen[0] = 1;
    }

    while (n > 0) {
        int digit = n % 10;
        seen[digit] = 1;
        n = n / 10;
    }

    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (seen[i] == 1) {
            count = count + 1;
        }
    }

    std::cout << "Количество различных цифр: " << count << std::endl;

    return 0;
}
