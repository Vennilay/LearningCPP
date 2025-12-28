#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    if (!N || !M) return 1;
    if (N > 75000 || M > 75000) {
        return 1;
    }

    long long totalRectangles = (N*(N+1)/2) * (M*(M+1)/2);

    cout << totalRectangles << endl;

    return 0;
}
