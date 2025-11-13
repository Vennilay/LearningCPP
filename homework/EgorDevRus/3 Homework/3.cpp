#include <windows.h>
#include <iostream>
#include <list>
#include <string>
#include <locale>
#include <fstream>
using namespace std;

bool isALF(char c);


int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RU");


	cout << "Введите строку: ";
	string line;
	cin >> line;



	list<char> list;
	char c;
	while (cin.get(c) && c != '\n') {
		if (isALF(c)) {
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

	return 0;
	}

bool isALF(char c) {
	return (c >= 'A' && c <= 'Z') ||
		(c >= 'a' && c <= 'z') ||
		(c >= 'А' && c <= 'я') ||
		(c == 'Ё' || c == 'ё');
}