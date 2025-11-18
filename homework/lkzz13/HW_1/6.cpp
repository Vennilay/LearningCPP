//1.6
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double s,n,m;;
    cin >> s >> m >> n;
    for(double r = -1; r < 1; r += 0.0001) {
        if(r!=0 && abs((s * r * pow((1 + r), n))/
            (12 * ((pow(1 + r, n) - 1))) - m) < 1.0) {
            cout << r * 100 << endl;
            break;
        }
    }
    return 0;
}