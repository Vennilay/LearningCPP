#include <iostream>
using namespace std;

int randomm(int m, int i, int c) {
    if (i == 0) {
        return 0;
    }

    return (m * randomm(m, i - 1, c) + i) % c;
}
int main() {
    cout << randomm(37, 3, 64) << endl;
    cout << randomm(25173, 13849, 65537) << endl;

}