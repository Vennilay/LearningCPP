#include <iostream>
using namespace std;

int n = 10;
int a[10];
int count_result = 0;

void generate(int t) {
    if (t == n - 1) {
        bool match = false;

        for (int i = 0; i < n; ++i) {
            if (a[i] == i + 1) {
                match = true;
                break;
            }
        }

        if (match) {
            count_result++;
        }
    } else {
        for (int j = t; j < n; ++j) {
            swap(a[t], a[j]);
            generate(t + 1);
            swap(a[t], a[j]);
        }
    }
}

int main() {

    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }

    generate(0);

    cout << "Количество подходящих ситуаций: " << count_result << endl;
    cout << "Ожидаемый ответ для n = 10: 2293839" << endl;

    return 0;
}
