#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;


int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    double N = 0;
    cin >> N;


    if (N < 0) {
        N = 1;
        for (int i = 0; i < 10; i++) {
            cout << N << endl;
            N++;
        }
    }

    else if(N == 0)
    {
        for (int i = 0; i < 10; i++) {
            N++;
            cout << N << endl;
        }
    }
    else if (ceil(N) == N) {
        for (int i = 0; i < 10; i++) {
            cout << N << endl;
            N++;
        }
    }
    else if (N > 0) {
        N = ceil(N);
        for (int i = 0; i < 10; i++) {
            cout << N << endl;
            N++;
        }
    }
}
