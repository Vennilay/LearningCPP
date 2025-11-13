	#include <iostream>
	#include <string>
	#include <fstream>
	#include <windows.h>
	using namespace std;

	int main()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		ofstream file("TEST.txt", ios_base::out);
		if(file.is_open()){
			file << "qsQSQS" << endl;
			file << "2135" << endl;
			file << "A7A7A7A7";
		}
		else { cout << "Ошибка!"; }
		file.close();

		ofstream file2("TEST.txt", fstream::app);
		if (file2.is_open()) {
			cout << "Введите строку: ";
			string a;
			cin >> a;
			file2 <<endl<< a;
			file2.close();
		}
		else { cout << "Ошибка"; }
		



		ifstream file1("TEST.txt");
		if (file1.is_open()) {
			string line;
			while (getline(file1, line)) {
				cout << line << endl;
			}
			file1.close();
		}
		else { cout << "Ошибка чтения файлы"; }
		





		return 0;

	}
