#include <iostream>
using namespace std;
int main() {
    long long n;
    cout << "Введите целое число n: ";
    cin >> n;

    n=llabs(n);
    bool symbol[10] = {false};

    if (n == 0) {
        symbol[0] = true;
    } else {
        while (n > 0) {
            const int d = static_cast<int>(n % 10);
            symbol[d] = true;
            n /= 10;
        }
    }
    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (symbol[i]) {
            ++count;
        }
    }
    cout << "Количество различных цифр: " << count << endl;
    return 0;
}