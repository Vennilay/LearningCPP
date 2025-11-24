#include <iostream>
#include <vector>
using namespace std;

// ===== Функция генерации перестановок =====
void perestanovka(vector<int>& arr, int step, int n, long long& count) {
    if (step == n) { // дошли до конца перестановки
        // проверка: есть ли хотя бы один совпавший номер
        for (int i = 0; i < n; i++) {
            if (arr[i] == i + 1) { // номера шагов начинаем с 1
                count++;
                break;
            }
        }
        return;
    }

    for (int m = step; m < n; m++) {
        swap(arr[step], arr[m]);           // поменять местами
        perestanovka(arr, step + 1, n, count); // рекурсивный вызов для следующего шага
        swap(arr[step], arr[m]);           // вернуть обратно
    }
}

int main() {
    int n = 10; // количество шариков
    vector<int> balls(n);
    for (int i = 0; i < n; i++)
        balls[i] = i + 1;

    long long count = 0; // счетчик перестановок с хотя бы одним совпадением
    perestanovka(balls, 0, n, count);

    cout << "Общее количество ситуаций, когда хотя бы один шарик совпадает с номером действия: "
         << count << endl;

    return 0;
}
