#include <iostream>
#include <algorithm>

int fact(const int n) {
    int f = 1;
    for (int i = 2; i <= n; ++i)
        f *= i;
    return f;
}

int main() {
    int n;
    std::cout << "Количество шариков: ";
    std::cin >> n;

    int a[12];
    for (int i = 0; i < n; ++i)
        a[i] = i + 1;

    int result = 0;
    const int total = fact(n);

    for (int i = 0; i < total; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[j] == j + 1) {
                ++result;
                break;
            }
        }
        std::next_permutation(a, a + n);
    }

    std::cout << "Результат: " << result << std::endl;
    return 0;
}