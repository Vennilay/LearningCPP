#include <iostream>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    if (!N || !M) return 1;
    if (N > 75000 || M > 75000 || N < 0 || M < 0) {
        return 2;
    }

    long long totalRectangles = (N*(N+1)/2) * (M*(M+1)/2);

    cout << totalRectangles << endl;

    return 0;
}