#include <chrono>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

string generateRandomString(int length) {
    string chars =
        // "abcdefghijklmnopqrstuvwxyz"
        // "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0"
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

void activity(string &vvod, int n, long &comparisons, long &movements, int alg) {
    auto start = chrono::high_resolution_clock::now();
    switch (alg) {
        case 1:
            selectionSort(vvod, n, comparisons, movements);
            break;
        default:;
    }
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration<double, milli>(end - start);
    cout << "Время выполнения: " << duration.count() << " мс\n";
    cout<<"Сп: "<<comparisons<<endl;
    cout<<"Мп: "<<movements<<endl;
    cout<<"Тп: "<<comparisons + movements<<endl;
    cout<<endl;
}

int main() {
    int test[8] = {100, 200, 500, 1000, 2000, 5000, 10000, 100000};
    string vvod;
    int n;
    int vvodStroki;
    long comparisons;
    long movements;

    int alg;
    cout<<"Выберите алгоритм сортировки:"<<endl<<"1)selection Sort"<<endl;
    cin>>alg;
    cin.ignore();

    cout<<"Ввод строки вручную или тестирование скорости:"<<endl<<"1) Вручную"<<endl<<"2) Тест"<<endl;
    cin>>vvodStroki;
    cin.ignore();
    switch (vvodStroki) {
        case 1:
            cout<<"Введите строку: "<<endl;
            getline(cin, vvod);
            n = vvod.size();
            activity(vvod, n, comparisons, movements, alg);
            break;
        case 2:
            for (int n : test){
                vvod = generateRandomString(n);
                cout<<"Длинна строки: "<<n<<endl;
                // cout<<"Cгенерированная строка: "<<vvod<<endl;

                activity(vvod, n, comparisons, movements, alg);

                // cout<<"Отсортированная строка: "<<vvod<<endl;
            }
            break;
        default:
            return 0;
    }
}