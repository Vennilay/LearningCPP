#include <iostream>
#include <algorithm>
using namespace std;

long long factorial(int n) {
    long long fact = 1;
    for (int i = 2; i <= n; ++i)
        fact *= i;
    return fact;
}

int main() {
    int n = 10;
    /*cout << "Введите количество шариков: ";
    cin >> n;*/

    int a[n];
    for (int i = 0; i < n; ++i)
        a[i] = i + 1;

    int result = 0;
    long long total = factorial(n);

    for (long long i = 0; i < total; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[j] == j + 1) {
                ++result;
                break;
            }
        }
        next_permutation(a, a + n);
    }

    cout << "Результат: " << result << endl;
    return 0;
}