#include <iostream>
#include <string>
using namespace std;

void FirstMetod(char x[], int &n, char key) {
    int i = 0;
    while (i < n) {
        if (x[i] == key) {
            for (int j = i; j < n - 1; j++) {
                x[j] = x[j + 1];
            }
            n = n - 1;
        } else {
            i = i + 1;
        }
    }
}

void SecondMetod(char x[], int &n, int key) {
    if (n <= 0) return;

    int j = 0;
    for (int i = 0; i < n; i++) {
        x[j] = x[i];
        if (x[i] != key) {
            j++;
        }
    }
    if (x[0] == key) {
        n = 0;
    } else {
        n = j;
    }
}
int main() {
    char arr[] = {'_', 'M', 'I', '_', '_', 'R', '_', '_', 'E', 'A', '_', '_'};
    int n = 12;
    const char key = '_';


    FirstMetod(arr, n, key);
    cout << "Result: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}