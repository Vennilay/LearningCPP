#include <cmath>
#include <iostream>


using namespace std;


int podborIJ(int n = 0) {
    int i, j;
    for (i = 0; pow(2, i) < n; i++) {}
    for (j = 0; pow(2, j) < n; j++) {}
    return {i, j};
}

// int shellSort () {
//     for (i = 0; i < n; i++) {}
// }

int main() {
    int n = 0;

    cout<<"Введите длину строки ";
    cin>>n;
    cout<<(podborIJ(n));
}