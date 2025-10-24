#include <fstream>
#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

int main() {

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    int N;
    cout << "Введите натуральное число:";
    cin >> N;

    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false; // 0 и 1 не являются простыми


    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }


    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            cout << i << " ";
        }
    }

    return 0;
}
