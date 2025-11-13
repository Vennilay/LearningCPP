#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ofstream file("Ex6.txt", ios_base::out);	
	if (file.is_open()) {
		int a;
		cout << "Введите количество чисел: ";
		cin >> a;
		cin.ignore();
		for (int i = 0; i < a; i++)
		{
			string line;
			getline(cin, line);

			file << line << endl;
		}
		file.close();
	}
		
		
	

	ifstream file_read("Ex6.txt");

	if (file_read.is_open()) {
		int sum = 0; 
		int number;
		string line;
		while (file_read >> number) {  
			sum += number; 
		}

		cout << "Сумма: " << sum;



		file_read.close();






	}



	return 0;
}

