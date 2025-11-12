#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	float N, k = 0;
	cout << "Введите число N: "; cin >> N;
	for (N; k < 10; N++) {
		if (N > 0) {
			N = ceil(N);
			k++;
			cout << N << ' ';
		}
		else {
			N=0;
		}
	}
}