#include <chrono>
#include <iostream>
#include <string>

using namespace std;

string worstCase(int n) {
    string result;
    while ((int)result.size() < n) {
        for (char c = '9'; c >= '0' && result.size() < n; --c) {
            result += c;
        }
    }
    return result;
}

string generateRandomString(int length) {
    string chars =
        // "abcdefghijklmnopqrstuvwxyz"
        // "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        // "!@#$%^&*()-_=+[]{};:,.<>/?"
    ;

    string result = "";

    for (int i = 0; i < length; i++) {
        result += chars[rand() % chars.size()];
    }

    return result;
}

void selectionSort(string &vvod, int n, long &comparisons, long &movements) {
    comparisons = 0;
    movements = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            comparisons++;
            if (vvod[j] < vvod[minIndex]) {
                minIndex = j;
            }
        }
        if (i != minIndex) {
            int temp = vvod[i];
            vvod[i] = vvod[minIndex];
            vvod[minIndex] = temp;
            movements += 3;
        }
    }
}

void exchangeSort(string &vvod, int n, long &comparisons, long &movements) {
    comparisons = 0;
    movements = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i+1; j < n; j++) {
            comparisons++;
            if (vvod[i] > vvod[j]) {
                int temp = vvod[i];
                vvod[i] = vvod[j];
                vvod[j] = temp;
                movements+=3;
            }
        }
    }
}

void activity(string &vvod, int n, long &comparisons, long &movements, int alg) {
    auto start = chrono::high_resolution_clock::now();

    switch (alg) {
        case 1:
            selectionSort(vvod, n, comparisons, movements);
            break;
        case 2:
            exchangeSort(vvod, n, comparisons, movements);
            break;
        default:
            return;
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration<double, milli>(end - start);

    cout << n << "\t"
         << duration.count() << "\t"
         << comparisons << "\t"
         << movements << "\t"
         << (comparisons + movements) << "\n";
}

int main() {
    int test[8] = {100, 200, 500, 1000, 2000, 5000, 10000, 100000};
    string vvod;
    int n;
    int vvodStroki;
    long comparisons;
    long movements;

    int alg;
    cout<<"Выберите алгоритм сортировки:"<<endl<<"1)Selection Sort"<<endl<<"2)Exchange Sort"<<endl;
    cin>>alg;
    cin.ignore();

    if (alg != 1 && alg != 2) {
        return 0;
    }

    cout<<"Ввод строки вручную или тестирование скорости:"<<endl<<"1) Вручную"<<endl<<"2) Тест"<<endl;
    cin>>vvodStroki;
    cin.ignore();
    switch (vvodStroki) {
        case 1:
            cout<<"Введите строку: "<<endl;
            getline(cin, vvod);
            n = vvod.size();
            cout << "количество\tвремя,мс\tСп\tМп\tТп\n";
            activity(vvod, n, comparisons, movements, alg);
            cout<<"Получившаяся строка: "<<vvod;
            break;
        case 2:
            cout << "количество\tвремя,мс\tСп\tМп\tТп\n";
            for (int n : test){
                vvod = generateRandomString(n);
                activity(vvod, n, comparisons, movements, alg);
            }
            break;
        default:
            return 0;
    }
}