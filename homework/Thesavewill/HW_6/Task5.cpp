#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <windows.h> // Необходим для функций SetConsoleCP и SetConsoleOutputCP
using namespace std;

int main() {
    // Настройка кодировки консоли для корректного вывода кириллицы (только для Windows)
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    long long N, K;
    cin >> N >> K;

    // Очередь с приоритетом (max-heap) для хранения размеров свободных интервалов.
    priority_queue<long long> pq;
    pq.push(N); // Изначально весь ряд - один большой интервал размера N.

    long long last_left_free = 0;
    long long last_right_free = 0;

    for (int i = 0; i < K; ++i) {
        long long current_size = pq.top();
        pq.pop();

        // Вычисляем количество свободных мест слева и справа от нового места.
        long long s1, s2;
        if (current_size % 2 != 0) {
            // Если нечетно, поровну свободных мест с обеих сторон.
            s1 = (current_size - 1) / 2;
            s2 = (current_size - 1) / 2;
        } else {
            // Если четно, выбирается одно из двух мест посередине.
            s1 = current_size / 2; // Больший интервал
            s2 = current_size / 2 - 1; // Меньший интервал
        }

        // Запоминаем размеры для последнего (К-го) школьника
        if (i == K - 1) {
            last_left_free = min(s1, s2);
            last_right_free = max(s1, s2);
            break; // Задача решена, выходим из цикла
        }

        // Добавляем новые интервалы обратно в очередь, если они не пустые.
        if (s1 > 0) pq.push(s1);
        if (s2 > 0) pq.push(s2);
    }

    cout << last_left_free << " " << last_right_free << endl;

    return 0;
}
