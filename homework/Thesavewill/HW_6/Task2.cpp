#include <iostream>
#include <windows.h> // Этот заголовок и функции не нужны для данной задачи
using namespace std;

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    long long m; // Используем long long для M до 2*10^9
    long long summ = 0, cf = 0, ct = 0;

    cout << "Введите M: ";
    if (!(cin >> m)) {
        return 1;
    }

    if (m < 3) {
        // Для M=1 и M=2 решения не существует
        cout << 0 << " " << 0 << endl;
        return 0;
    }

    // Логика, приближенная к вашему стилю с циклами while/if
    // Пытаемся найти решение, перебирая количество 4-лопастных (cf) спиннеров
    bool found = false;
    for (cf = m / 4; cf >= 0; --cf) {
        summ = m - 4 * cf; // summ - оставшиеся лопасти после вычета cf*4
        if (summ % 3 == 0) {
            ct = summ / 3;
            found = true;
            break; // Нашли первое решение, выходим из цикла for
        }
    }

    if (found) {
        // Выводим результат в формате "ct cf" (как просит задача)
        cout << ct << " " << cf << endl;
        // Если хотите увидеть вывод в вашем оригинальном стиле (например, 2*3 + 1*4 = 10):
        // cout << ct << "*3 + " << cf << "*4 = " << m << endl;
    } else {
        // Если Денис не может использовать ровно М лопастей...
        // (Для m>=3 это условие не должно срабатывать, но на всякий случай)
        cout << 0 << " " << 0 << endl;
    }

    return 0;
}