#include <iostream>
#include <map>

using namespace std;

int main() {
    long long n, k;

    cout << "Введите количество мест (N) и количество школьников (K): ";
    cin >> n >> k;

    map<long long, long long> segments;
    segments[n] = 1;

    while (k > 0) {
        auto it = segments.end();
        it--;
        long long length = it->first;
        long long count = it->second;
        segments.erase(it);

        long long left_part = (length - 1) / 2;
        long long right_part = length / 2;

        if (k <= count) {
            cout << "Слева: " << left_part << ", Справа: " << right_part << endl;
            return 0;
        }

        k -= count;

        segments[left_part] += count;
        segments[right_part] += count;
    }

    return 0;
}
