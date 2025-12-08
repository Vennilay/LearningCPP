#include <iostream>
#include <vector>
using namespace std;

void perestanovka(vector<int>& arr, int step, int n, int& count) {
    if (step == n) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == i + 1) {
                count++;
                break;
            }
        }
    }

    for (int i = step; i < n; i++) {
        swap(arr[step], arr[i]);
        perestanovka(arr, step + 1, n, count);
        swap(arr[step], arr[i]);
    }
}

int main() {
    int n = 10;
    vector<int> balls(n);
    for (int i = 0; i < n; i++)
        balls[i] = i + 1;

    int count = 0;
    perestanovka(balls, 0, n, count);

    cout << "Количество перестановок с хотя бы одним совпадением: " << count << endl;

    return 0;
}