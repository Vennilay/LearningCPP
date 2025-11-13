#include <iostream>
#include <windows.h>
#include <cmath>
#include <vector>
using namespace std;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int  N;
    cout << "Введите число: ";
    cin >> N;
    // 1 способ перебором
    /*for (int num = 2; num <= N; num++) {
        bool prostoe = true;

        for (int a = 2; a <= sqrt(N); a++) {

            if (num % a == 0) {
                prostoe = false;
                break;

            }


        }

        if (prostoe) {
            cout << num << " ";
        }
    }*/

    //2 способ решето

    vector<bool> prime(N + 1, true);

    for (int num = 2; num <= sqrt(N); num++) {
        if (prime[num]) {
            for (int j= num * num; j <= N;j+=num) {
                prime[j] = false;
            }
        }
    }

    for (int i=2; i <= N; i++) {
        if (prime[i]) {
            cout << i << " ";
        }
    }


    return 0;
}
