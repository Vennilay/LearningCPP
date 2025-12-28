#include <iostream>
#include <map>
using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;
    if (!N || !K) return 1;

    map<long long, long long, greater<long long>> mp;
    mp[N] = 1;

    while (true) {
        long long cur = mp.begin()->first;
        long long cnt = mp.begin()->second;

        mp.erase(mp.begin());

        long long left  = (cur - 1) / 2;
        long long right = cur / 2;

        if (K <= cnt) {
            cout << min(left, right) << "\n" << max(left, right) << endl;
            break;
        }

        K -= cnt;

        mp[left]  += cnt;
        mp[right] += cnt;
    }

    return 0;
}