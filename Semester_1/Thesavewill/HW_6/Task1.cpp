#include <iostream>
using namespace std;

int main() {
    int a, b ,c, cost = 0, n = 0 , remember = 0, ans = 0;
    cin >> a >> b >> c;

    while (cost < c) {
        ++n;
        cost = a + b * n;
        if (cost > c && remember != 0) {
            ans = remember;
        }
        else if (cost > c && remember == 0){
            ans = remember;
        }
        remember = n;
    }
    cout << ans;
    return 0;
}