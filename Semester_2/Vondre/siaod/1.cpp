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


void delFirstMetod(char*x, int &n, char key, int &comparisons, int &movements) {

    comparisons = 0;
    movements = 0;
    int i = 0;
    while (i <= n - 1) {
        comparisons++;
        if (x[i] == key) {
            for (int j = i; j <= n-1; j++) {
                x[j] = x[j+1];
                movements++;
            }
            n--;
        }
        else {
            i++;
        }
    }
}

void activity(char &key, int n, string &vvod, int &comparisons, int &movements){
    cout<<"Введите символ который нужно удалить: ";
    cin>>key;

    cout<<"Начальная длина строки: "<<n<<endl;

    char*x = new char[n + 1];

    strcpy(x,vvod.c_str());

    auto start = chrono::high_resolution_clock::now();
    delFirstMetod(x,n,key, comparisons, movements);
    auto end = chrono::high_resolution_clock::now();

    cout<<"Получившаяся строка: "<<x<<endl;
    cout<<"Новая длина: "<<n<<endl;
    delete[] x;

    auto duration = chrono::duration<double, milli>(end - start);
    cout << "Время выполнения: " << duration.count() << " мс\n";
    cout<<"Сп: "<<comparisons<<endl;
    cout<<"Мп: "<<movements<<endl;
    cout<<"Тп: "<<comparisons + movements<<endl;
}

int main() {

    int test[7] = {100, 200, 500, 1000, 2000, 5000, 10000};

    int comparisons;
    int movements;

    string vvod;
    int n;
    char key;

    int vibor;

    cout<<"Ввод строки вручную или тестирование скорости:"<<endl<<"1) Вручную"<<endl<<"2) Тест"<<endl;
    cin>>vibor;
    cin.ignore();

    if (vibor == 1) {
        cout<<"Введите строку: "<<endl;
        getline(cin, vvod);
        n = vvod.size();
        activity(key, n, vvod, comparisons, movements);
    }

    if (vibor == 2) {
        for (int n : test)
        {
            vvod = generateRandomString(n);
            cout<<"Cгенерированная строка: "<<vvod<<endl;

            activity(key, n, vvod, comparisons, movements);
        }
    }
    else {
        return 0;
    }
}