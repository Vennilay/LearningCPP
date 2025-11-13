#include <windows.h>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	ofstream file("Ex num 2.txt", ios_base::out);
	if (file.is_open()) {
		int a; 
			
		cout << "Введите количество строк в файле: ";
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
	else { cout << "файл не открылся";}
	

	ifstream file_read("Ex num 2.txt");
	if (file_read.is_open())
	{
		char c;
		while (file_read.get(c)) {
			if (c >= '0' && c <= '9') {
				cout << c;
			}
		}
		file_read.close();
	}
	else { cout << "файл не открылся";}


	return 0;
}
