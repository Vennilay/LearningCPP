#include <iostream>

int main() {
    long long n = 0, m = 0;

    if (std::cin >> n >> m) {
        const long long res = (n * (n + 1) / 2) * (m * (m + 1) / 2);

        std::cout << res << std::endl;
    }

    return 0;
}
