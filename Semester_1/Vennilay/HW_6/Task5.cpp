#include <iostream>
#include <map>

int main() {
    long long n, k;

    std::cout << "Введите N и K: ";
    std::cin >> n >> k;

    std::cout << "\nНачинаем поиск. Всего мест: " << n << ", целевой школьник: " << k << std::endl;

    std::map<long long, long long> segments;
    segments[n] = 1;

    while (k > 0) {
        auto it = segments.end();
        --it;
        const long long length = it->first;
        const long long count = it->second;
        segments.erase(it);

        std::cout << "--------------------------------" << std::endl;
        std::cout << "Берем максимальный отрезок: " << length << " (таких штук: " << count << ")" << std::endl;

        long long left_part = (length - 1) / 2;
        long long right_part = length / 2;

        std::cout << "Если сесть сюда, то слева будет " << left_part << ", справа " << right_part << std::endl;

        if (k <= count) {
            std::cout << "Нашли! Наш школьник садится на одно из этих мест." << std::endl;
            std::cout << "Ответ -> Слева: " << left_part << ", Справа: " << right_part << std::endl;
            return 0;
        }

        k -= count;
        std::cout << "Школьник не здесь. Пропускаем эти " << count << " мест. Осталось пропустить: " << k << std::endl;

        segments[left_part] += count;
        segments[right_part] += count;
        std::cout << "Добавляем в очередь новые отрезки (" << left_part << " и " << right_part << ") по " << count << " шт." << std::endl;
    }

    return 0;
}