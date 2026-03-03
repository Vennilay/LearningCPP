#include <chrono>
#include <cstring>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string generateRandomString(int length) {
    string chars =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        "!@#$%^&*()-_=+[]{};:,.<>/?";

    string result = "";

    for (int i = 0; i < length; i++) {
        result += chars[rand() % chars.size()];
    }

    return result;
}



void delFirstMetod(char*x, int &n, char key) {
    int i = 0;
    while (i <= n) {
        if (x[i] == key) {
            for (int j = i; j <= n-1; j++) {
                x[j] = x[j+1];
            }
            n--;
        }
        else {
            i++;
        }
    }
}

int main() {
    auto start = chrono::high_resolution_clock::now();


    string vvod;
    int n;
    char key;

    int vibor;

    cout<<"Ввод строки вручную или тестирование скорости:"<<endl<<"1) Вручную"<<endl<<"2) Тест"<<endl;
    cin>>vibor;

    if (vibor == 1) {
        cout<<"Введите строку: ";
        getline(cin,vvod);
        n = vvod.size();
    }

    auto point1 = chrono::high_resolution_clock::now(); //отделяем код генерации строки от основной программы
    cout<<chrono::duration_cast<chrono::milliseconds>(point1);;

    if (vibor == 2) {
        cout<<"Введите длину строки: ";
        cin>>n;
        vvod = generateRandomString(n);
        cout<<"Cгенерированная строка: "<<vvod<<endl;
    }
    else {
        return 0;
    }

    auto point2 = chrono::high_resolution_clock::now();

    cout<<chrono::duration_cast<chrono::milliseconds>(point2);



    cout<<"Введите символ который нужно удалить: ";
    cin>>key;



    cout<<"Начальная длина строки: "<<n<<endl;

    char*x = new char[n + 1];

    strcpy(x,vvod.c_str());

    delFirstMetod(x,n,key);

    cout<<"Получившаяся строка: "<<x<<endl;
    cout<<"Новая длина: "<<n<<endl;
    delete[] x;

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Время выполнения: " << duration.count() << " мс\n";

}