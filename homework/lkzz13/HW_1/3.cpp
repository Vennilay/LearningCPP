//1.3
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double n;
    cin >> n;
    for (int i=ceil(n);i < (ceil(n)+10);i++) {
        cout << i << " ";
    }
}