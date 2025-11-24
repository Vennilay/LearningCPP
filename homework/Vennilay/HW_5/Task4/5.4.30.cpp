#include <iostream>

int main() {
    long long n;
    std::cout << "Введите целое число n: ";
    std::cin >> n;

    n = std::llabs(n);

    bool used[10] = {false};

    if (n == 0) {
        used[0] = true;
    } else {
        while (n > 0) {
            const int d = static_cast<int>(n % 10);
            used[d] = true;
            n /= 10;
        }
    }

    int count = 0;
    for (int d = 0; d < 10; ++d) {
        if (used[d]) {
            ++count;
        }
    }

    std::cout << "Количество различных цифр: " << count << std::endl;
    return 0;
}
