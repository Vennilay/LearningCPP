#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int i;
	for (i = 0; i < 3;i++) {
		cout << "\x1B[44m\x1B[37m* * * * * * * * \x1B[41m                              \x1B[31m" << endl;
		cout << "\x1B[44m\x1B[37m* * * * * * * * \x1B[47m                              " << endl;
	}
	for (i = 0; i < 4;i++) {
		cout << "\x1B[41m                                              " << endl;
		cout << "\x1B[47m                                              \x1B[0m" << endl;
	}
}