#include <chrono>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

string generateRandomString(int length) {
    string chars =
        // "abcdefghijklmnopqrstuvwxyz"
        // "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "12"
        // "!@#$%^&*()-_=+[]{};:,.<>/?"
    ;

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
    while (i < n) {
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
    x[n] = '\0';
}

void delOtherMethod(char*x, int &n, char key, int &comparisons, int &movements) {
    comparisons = 0;
    movements = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        comparisons++;

        if (x[i] != key)
        {
            x[j] = x[i];
            movements++;
            j++;
        }
    }
    n = j;
    x[n] = '\0';
}

void activity(char &key, int n, string &vvod, int &comparisons, int &movements, int alg){
    cout<<"Начальная длина строки: "<<n<<endl;

    char*x = new char[n + 1];

    strcpy(x,vvod.c_str());

    auto start = chrono::high_resolution_clock::now();
    switch (alg) {
        case 1:
            delFirstMetod(x,n,key, comparisons, movements);
            break;
        case 2:
            delOtherMethod(x,n,key, comparisons, movements);
            break;
        default:
            delete[] x;
    }

    auto end = chrono::high_resolution_clock::now();

    cout<<"Получившаяся строка: "<<x<<endl;
    cout<<"Новая длина: "<<n<<endl;
    delete[] x;

    auto duration = chrono::duration<double, milli>(end - start);
    cout << "Время выполнения: " << duration.count() << " мс\n";
    cout<<"Сп: "<<comparisons<<endl;
    cout<<"Мп: "<<movements<<endl;
    cout<<"Тп: "<<comparisons + movements<<endl;
    cout<<endl;
}

int main() {
    cout<<"Выберите алгоритм удаления:"<<endl<<"1)delFirstMetod"<<endl<<"2)delOtherMethod"<<endl;
    int alg;
    cin>>alg;
    cin.ignore();

    if (alg != 1 && alg != 2) {
        cout<<"Ошибка выбора";
        return 0;
    }

    int test[4] = {10, 100, 1000, 10000};

    int comparisons;
    int movements;

    string vvod;
    int n;
    char key;

    int vibor;

    cout<<"Ввод строки вручную или тестирование скорости:"<<endl<<"1) Вручную"<<endl<<"2) Тест"<<endl;
    cin>>vibor;
    cin.ignore();

    switch (vibor) {
        case 1:
            cout<<"Введите строку: "<<endl;
            getline(cin, vvod);
            n = vvod.size();
            cout<<"Введите символ который нужно удалить: ";
            cin>>key;
            activity(key, n, vvod, comparisons, movements, alg);
            break;
        case 2:
            cout<<"Введите символ который нужно удалить: ";
            cin>>key;
            for (int n : test)
            {
                vvod = generateRandomString(n);
                cout<<"Cгенерированная строка: "<<vvod<<endl;

                activity(key, n, vvod, comparisons, movements, alg);
            }
            break;
        default:
            cout<<"Ошибка выбора";
            return 0;
    }
}