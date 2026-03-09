#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <chrono>
#include <string>
using namespace std;
using namespace chrono;

long long comparisons = 0;
long long movements   = 0;

void delFirstMethod(char* x, int& n, char key) {
    comparisons = 0;
    movements   = 0;
    int i = 0;
    while (i < n) {
        comparisons++;
        if (x[i] == key) {
            for (int j = i; j < n - 1; j++) {
                x[j] = x[j + 1];
                movements++;
            }
            n--;
        } else {
            i++;
        }
    }
}

void delOtherMethod(char* x, int& n, char key) {
    comparisons = 0;
    movements   = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
        x[j] = x[i];
        movements++;
        comparisons++;
        if (x[i] != key) {
            j++;
        }
    }

    n = j;
}

struct Result { long long comp, move; double ms; };
typedef void (*MethodFn)(char*, int&, char);
typedef void (*FillFn)  (char*, int,  char);

Result runMethod(MethodFn fn, const char* src, int n, char key) {
    char* tmp = new char[n];
    memcpy(tmp, src, n);
    int sz = n;

    auto t1 = high_resolution_clock::now();
    fn(tmp, sz, key);
    auto t2 = high_resolution_clock::now();

    double ms = duration<double, milli>(t2 - t1).count();
    Result r  = { comparisons, movements, ms };
    delete[] tmp;
    return r;
}

void fillAll   (char* a, int n, char key){ for(int i=0;i<n;i++) a[i]=key;                              }
void fillNone  (char* a, int n, char key){ for(int i=0;i<n;i++) a[i]=(char)(key+1);                    }
void fillRandom(char* a, int n, char key){ for(int i=0;i<n;i++) a[i]=(rand()%2==0)?key:(char)(key+1); }

void printTable(const string& title,
                int* sizes, int cnt,
                char key,
                FillFn   fillFn,
                MethodFn method)
{
    const int Cn = 9;
    const int Ct = 14;   // Время(мс)
    const int Cs = 14;   // Сп
    const int Cm = 14;   // Мп
    const int Cp = 14;   // Тп
    const int W  = Cn + Ct + Cs + Cm + Cp;
    const string SEP(W, '-');

    cout << "\n" << title << "\n" << SEP << "\n";
    cout << left  << setw(Cn) << "n"
         << right << setw(Ct) << "Время(мс)"
                  << setw(Cs) << "Сп"
                  << setw(Cm) << "Мп"
                  << setw(Cp) << "Тп=Сп+Мп"
         << "\n"  << SEP << "\n";

    for (int k = 0; k < cnt; k++) {
        int   n   = sizes[k];
        char* arr = new char[n];
        fillFn(arr, n, key);
        Result r  = runMethod(method, arr, n, key);
        delete[] arr;

        long long tp = r.comp + r.move;

        cout << left  << setw(Cn) << n
             << right << setw(Ct) << fixed << setprecision(4) << r.ms
                      << setw(Cs) << r.comp
                      << setw(Cm) << r.move
                      << setw(Cp) << tp
             << "\n";
    }
    cout << SEP << "\n";
}

int main() {
    srand(42);

    int sizes[] = { 100, 200, 500, 1000, 2000, 5000, 10000, 100000 };
    int cnt     = 8;
    char key    = 'A';

    // ════════════════════════════════════════════════════════════
    cout << "\n╔══════════════════════════════════════════╗\n";
    cout <<   "║         delFirstMethod                   ║\n";
    cout <<   "╚══════════════════════════════════════════╝\n";

    printTable("  [ЛУЧШИЙ СЛУЧАЙ]  ни один элемент не удаляется (в)",
               sizes, cnt, key, fillNone,   delFirstMethod);

    printTable("  [СРЕДНИЙ СЛУЧАЙ] случайное заполнение (~50% ключ) (б)",
               sizes, cnt, key, fillRandom, delFirstMethod);

    printTable("  [ХУДШИЙ СЛУЧАЙ]  все элементы = ключ, удаляются все (а)",
               sizes, cnt, key, fillAll,    delFirstMethod);

    // ════════════════════════════════════════════════════════════
    cout << "\n╔══════════════════════════════════════════╗\n";
    cout <<   "║         delOtherMethod                   ║\n";
    cout <<   "╚══════════════════════════════════════════╝\n";

    printTable("  [ЛУЧШИЙ СЛУЧАЙ]  ни один элемент не удаляется (в)",
               sizes, cnt, key, fillNone,   delOtherMethod);

    printTable("  [СРЕДНИЙ СЛУЧАЙ] случайное заполнение (~50% ключ) (б)",
               sizes, cnt, key, fillRandom, delOtherMethod);

    printTable("  [ХУДШИЙ СЛУЧАЙ]  все элементы = ключ, удаляются все (а)",
               sizes, cnt, key, fillAll,    delOtherMethod);

    // ════════════════════════════════════════════════════════════
    cout << "\n╔══════════════════════════════════════════════════════════════╗\n";
    cout <<   "║  АНАЛИЗ СЛОЖНОСТИ                                            ║\n";
    cout <<   "╚══════════════════════════════════════════════════════════════╝\n";
    cout << "\n";
    cout << "┌──────────────┬──────────────────────────┬──────────────────────────┐\n";
    cout << "│ Случай       │    delFirstMethod        │    delOtherMethod        │\n";
    cout << "├──────────────┼──────────────────────────┼──────────────────────────┤\n";
    cout << "│ Лучший  (в)  │ O(n)  — 0 перестановок  │ O(n)  — 2n перест.       │\n";
    cout << "│ Средний (б)  │ O(n²) — ~n²/4 перест.   │ O(n)  — ~1.5n перест.    │\n";
    cout << "│ Худший  (а)  │ O(n²) — n*(n-1)/2 пер.  │ O(n)  — n перест.        │\n";
    cout << "└──────────────┴──────────────────────────┴──────────────────────────┘\n";
    cout << "\n";
    cout << "delFirstMethod: O(n) только если нечего удалять,\n";
    cout << "                иначе каждый сдвиг — O(n) => итого O(n^2).\n\n";
    cout << "delOtherMethod: всегда O(n) независимо от данных.\n";
    cout << "                Лучший = Средний = Худший по числу сравнений.\n";

    return 0;
}
