#include <iostream>
#include <map>

int main() {
    long long n = 0, k = 0;

    std::cout << "Введите N (места) и K (школьники): ";
    if (!(std::cin >> n >> k)) return 0;

    std::map<long long, long long, std::greater<long long>> segments;

    segments[n] = 1;

    std::cout << "Начало: " << n << " мест, " << k << " школьников.\n";

    while (k > 0) {
        const auto it = segments.begin();

        const long long current_length = it->first;
        const long long count = it->second;

        std::cout << "------------------------------------------------\n";
        std::cout << "Самый большой отрезок сейчас: длина " << current_length
                  << ", таких отрезков: " << count << " шт.\n";
        std::cout << "Осталось посадить школьников: " << k << "\n";

        segments.erase(it);

        if (k <= count) {
            std::cout << "Школьников (" << k << ") <= Отрезков (" << count << ").\n";
            std::cout << "Значит, наш последний школьник садится именно сюда!\n";

            const long long left_part = (current_length - 1) / 2;
            const long long right_part = current_length / 2;

            std::cout << "Ответ: " << left_part << " " << right_part << std::endl;
            return 0;
        }

        std::cout << "Школьников много. Все " << count << " отрезков занимаются и делятся.\n";

        k -= count;

        long long left_part = (current_length - 1) / 2;
        long long right_part = current_length / 2;

        std::cout << "Отрезок " << current_length << " распадается на "
                  << left_part << " и " << right_part << ".\n";

        if (left_part > 0) {
            segments[left_part] += count;
            std::cout << "Добавлено " << count << " отрезков длины " << left_part << "\n";
        }
        if (right_part > 0) {
            segments[right_part] += count;
            std::cout << "Добавлено " << count << " отрезков длины " << right_part << "\n";
        }
    }

    return 0;
}