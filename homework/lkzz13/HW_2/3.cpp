//2.3
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double n;
    cin >> n;
    if (n<=0) {
        for (int i=1;i<11;i++) {
            cout << i<<" ";
        }
    }else {
        for (int i=ceil(n);i < (ceil(n)+10);i++) {
            cout << i << " ";
        }
    }

}