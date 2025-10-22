#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>

using namespace std;

int main() {
    int N;
    cout << "Введите натуральное число:";
    cin >> N;

    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false; // 0 и 1 не являются простыми

    // Решето Эратосфена
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // Собираем и выводим простые числа
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            cout << i << " ";
        }
    }

    return 0;
}