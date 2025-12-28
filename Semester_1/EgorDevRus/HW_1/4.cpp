#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	bool day,lamp,stors;

	char dayinp, lampinp, storsinp;

	cout << "сейчас день? y/n\n";
	cin >> dayinp;
	if (dayinp == 'y' || dayinp == 'Y') {
		day = true;
	}
	else {
		day = false;
	}
	
	cout << "лампа включена? y/n\n";
	cin >> lampinp;
	switch (lampinp) {
	case 'y':lamp = true; break;
	case 'Y':lamp = true; break;

	case 'n':lamp = false; break;
	case 'N':lamp = false; break;

	}


	cout << "шторы раздвинуты? y/n\n";
	cin >> storsinp;
	if (storsinp == 'Y' || storsinp == 'y') {
		stors = true;
	}
	else {
		stors = false;
	}

	if (day && stors || lamp) {
		cout << "В комнате светло";
	}
	else {
		cout << "В комнате темно";
	}


	return 0;

}