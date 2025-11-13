#include <cmath>
#include <windows.h>
#include <string>
#include <list>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

bool isALF(char c);
void ex1();
void ex2();
void ex3();
void ex4();
void ex5();
void ex6();

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int ex;
    do {
        cout << endl; cout << endl;
        system("cls");
        cout << "1 => «Копирование файла»" << endl;
        cout << "2 => «Фильтр»" << endl;
        cout << "3 => «Сортировка букв»" << endl;
        cout << "4 => е «Алгоритм Евклида»" << endl;
        cout << "5 => «Решето Эратосфена»" << endl;
        cout << "6 => Разветвление" << endl;
        cout << "0 => «Файл»" << endl;
        cout << "Выберите задание: " << endl;
        cin >> ex;

        cout << endl;
        switch (ex) {
        case 1: ex1(); break;
        case 2: ex2(); break;
        case 3: ex3(); break;
        case 4: ex4(); break;
        case 5: ex5(); break;
        case 6: ex6(); break;
        case 0: cout << "Выход" << endl; break;
        default: cout << "Неверный выбор!" << endl;
        }

        if (ex != 0) {
            cout << endl;
            system("pause");
        }

    } while (ex != 0);
    return 0;
}

void ex1() {
    ofstream file("EX1.txt", ios_base::out);
    if (file.is_open()) {
        file << "qsQSQS" << endl;
        file << "2135" << endl;
        file << "A7A7A7A7";
    }
    else { cout << "Ошибка!"; }
    file.close();

    ofstream file2("EX1.txt", fstream::app);
    if (file2.is_open()) {
        cout << "Введите строку: ";
        string a;
        cin >> a;
        file2 << endl << a;
        file2.close();
    }
    else { cout << "Ошибка"; }

    ifstream file1("EX1.txt");
    if (file1.is_open()) {
        string line;
        while (getline(file1, line)) {
            cout << line << endl;
        }
        file1.close();
    }
    else { cout << "Ошибка чтения файлы"; }
}
void ex2(){
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
    else { cout << "файл не открылся"; }


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
    else { cout << "файл не открылся"; }
}
void ex3(){
    setlocale(LC_ALL, "RU");


    cout << "Введите строку: ";
    string line;
    cin.ignore();
    getline(cin, line);

    list<char> list;
    char c;
    for (char c:line) {
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
                cout << "Ошибка: посторонний символ после 30-ой буквы"<<endl;

                return;
            }
        }
    }


    list.sort();
    
    for (char ch : list) {
        cout << ch;
    }

}
void ex4(){
    int a, b;



    // 1 способ делением
    cout << "Введите первое число(a): ";
    cin >> a;

    cout << "Введите второе число(b): ";
    cin >> b;

    while (a != 0 && b != 0) {
        if (a > b) a %= b;
        else b %= a;
    }

    int res = a + b;
    cout << "наибольший общий делитель(делением): " << res << endl;


    //2 способ вычитанием

    int M, N;
    cout << "Введите первое число(M): ";
    cin >> M;
    cout << "Введите второе число(N): ";
    cin >> N;

    while (M != N) {
        if (M > N) M -= N;
        else N -= M;
    }
    cout << "наибольший общий делитель(вычитанием): " << M;
}
void ex5(){int  N;
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

}
void ex6() {
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
        float sum = 0;
        float number;
        string line;
        while (file_read >> number) {
            sum += number;
        }

        cout << "Сумма: " << sum;



        file_read.close();
    }
}

bool isALF(char c) {
    return (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z') ||
        (c >= 'А' && c <= 'я') ||
        (c == 'Ё' || c == 'ё');
}

