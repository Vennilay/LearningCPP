#include <windows.h>
#include <iostream>
#include <list>
#include <string>
#include <locale>
#include <fstream>
using namespace std;

bool isALF1(char c);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RU");


	ofstream file("EX num 3.txt", ios_base::out);

	if (file.is_open()) {

		cout << "Введите строку: ";
		string line;
		getline(cin, line);
		file << line << endl;

		file.close();
	}
	else { cout << "Файл не открылся"; }

	ifstream file_read("Ex num 3.txt");

	if (file_read.is_open()) {
		list<char> list;
		char c;
		while (file_read.get(c) && c != '\n') {
			if (isALF1(c)) {
				if (list.size() < 30) {
					list.push_back(c);
				}
				//Ошибка при  превышении 30 символов
				//else { cout << "больше 30 символов"; return 1; }
			}

			else {
				//Ошибка при посторонних символах после 30-ой буквы
				if (list.size() >= 30) {
					cout << "Ошибка: посторонний символ после 30-ой буквы";
					return 1;
				}
			}
		}
		list.sort();

		for (char ch : list) {
			cout << ch;
		}





		file_read.close();
	}




	return 0;
}

bool isALF1(char c) {
	return (c >= 'A' && c <= 'Z') ||
		(c >= 'a' && c <= 'z') ||
		(c >= 'А' && c <= 'я') ||
		(c == 'Ё' || c == 'ё');
}