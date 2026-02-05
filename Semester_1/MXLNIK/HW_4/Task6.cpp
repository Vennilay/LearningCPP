#include <iostream>
#include <windows.h>
#include <iomanip>
#include <algorithm>
using namespace std;

int find_max_index(float num1, float num2, float num3)
{
	float nums[3] = { num1, num2, num3 };
	float max_val = *max_element(nums, nums + 3);
	for (int i = 0; i < 3; i++)
	{
		if (max_val == nums[i])
		{
			return i + 1;
		}
	}
}

int find_min_index(float num1, float num2, float num3)
{
	float nums[3] = { num1, num2, num3 };
	float min_val = *min_element(nums, nums + 3);
	for (int i = 0; i < 3; i++)
	{
		if (min_val == nums[i])
		{
			return i + 1;
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	float matrix_A[3][4] = {{5, 2, 0, 10}, {3, 5, 2, 5}, {20, 0, 0, 0}};
	float matrix_B[4][2] = {{1.2, 0.5}, {2.8, 0.4}, {5.0, 1.0}, {2.0, 1.5}};
	float matrix_C[3][2] = {{0, 0}, {0, 0}, {0, 0}};
	float rev, comm;


	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				matrix_C[i][j] += matrix_A[i][k] * matrix_B[k][j];
			}
		}
	}

	cout << "Матрица C:\n" << "           Выручка  Комиссионные" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Продавец " << i + 1 << "  ";
		for (int j = 0; j < 2; j++)
		{
			cout << fixed << setprecision(1) << matrix_C[i][j] << "        ";
		}
		cout << endl;
	}

	rev = matrix_C[0][0] + matrix_C[1][0] + matrix_C[2][0];
	comm = matrix_C[0][1] + matrix_C[1][1] + matrix_C[2][1];
	cout << endl << "Больше всех выручил: Продавец " << find_max_index(matrix_C[0][0], matrix_C[1][0], matrix_C[2][0]) << endl;
	cout << "Меньше всех выручил: Продавец " << find_min_index(matrix_C[0][0], matrix_C[1][0], matrix_C[2][0]) << endl;
	cout << "Наибольшие комиссионные получил: Продавец " << find_max_index(matrix_C[0][1], matrix_C[1][1], matrix_C[2][1]) << endl;
	cout << "Наименьшие комиссионные получил: Продавец " << find_min_index(matrix_C[0][1], matrix_C[1][1], matrix_C[2][1]) << endl;
	cout << "Общая сумма выручки: " << rev << endl;
	cout << "Общая сумма комиссионных: " << comm << endl;
	cout << "Общая сумма денег, прошедших через руки продавцов: " << rev + comm << endl;

	return 0;
}
