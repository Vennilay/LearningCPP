#include <iostream>

int main() {

    long long n = 0, k = 0;

    std::cout << "Введите N (всего мест) и K (номер школьника): ";
    std::cin >> n >> k;

    long long len1 = n;
    long long count1 = 1;

    long long len2 = n - 1;
    long long count2 = 0;

    long long step = 1;

    while (k > 0) {
        std::cout << "\nШАГ " << step << ":" << std::endl;
        std::cout << "Два типа свободных участков:" << std::endl;
        std::cout << "1) Длина " << len1 << " (количество: " << count1 << ")" << std::endl;
        if (count2 > 0) {
            std::cout << "2) Длина " << len2 << " (количество: " << count2 << ")" << std::endl;
        } else {
            std::cout << "2) Второго типа пока нет (количество: 0)" << std::endl;
        }
        std::cout << "Нужно посадить еще " << k << " человек" << std::endl;
        std::cout << "------------------------------------------------" << std::endl;

        std::cout << "Проверяем самую большую длину (" << len1 << ")..." << std::endl;
        std::cout << "К (" << k << ") <= Количества мест (" << count1 << ")?" << std::endl;

        if (k <= count1) {
            std::cout << "Школьник попадает в этот участок" << std::endl;
            std::cout << "Вычисляем свободные места слева и справа..." << std::endl;

            const long long left = (len1 - 1) / 2;
            const long long right = len1 / 2;

            std::cout << "Формула: (" << len1 << " - 1) / 2 = " << left << std::endl;
            std::cout << "Формула: " << len1 << " / 2 = " << right << std::endl;
            std::cout << "\nОТВЕТ: " << left << " " << right << std::endl;
            return 0;
        }

        std::cout << "НЕТ. Мест не хватает." << std::endl;
        std::cout << "Заполняем все эти " << count1 << " мест и вычеркиваем школьников." << std::endl;
        k = k - count1;
        std::cout << "Осталось посадить: " << k << std::endl;

        if (count2 > 0) {
            std::cout << "------------------------------------------------" << std::endl;
            std::cout << "Проверяем вторую длину (" << len2 << ")..." << std::endl;
            std::cout << "Сравниваем: К (" << k << ") <= Количества мест (" << count2 << ")?" << std::endl;

            if (k <= count2) {
                std::cout << "Школьник попадает в этот участок." << std::endl;
                const long long left = (len2 - 1) / 2;
                const long long right = len2 / 2;

                std::cout << "Формула: (" << len2 << " - 1) / 2 = " << left << std::endl;
                std::cout << "Формула: " << len2 << " / 2 = " << right << std::endl;
                std::cout << "\nОТВЕТ: " << left << " " << right << std::endl;
                return 0;
            }

            std::cout << "Мест снова не хватает" << std::endl;
            k = k - count2;
            std::cout << "Заполнили эти места. Осталось посадить: " << k << std::endl;
        }

        std::cout << "------------------------------------------------" << std::endl;
        std::cout << "Генерация новых участков для следующего шага:" << std::endl;

        long long next_len1, next_count1, next_len2, next_count2;

        if (len1 % 2 == 1) {
            std::cout << "Длина " << len1 << " НЕЧЕТНАЯ" << std::endl;
            std::cout << "Она делится на два одинаковых участка по " << len1 / 2 << "." << std::endl;

            next_len1 = len1 / 2;
            next_count1 = count1 * 2 + count2;
            next_len2 = (len1 / 2) - 1;
            next_count2 = count2;

            std::cout << "Новое количество длинных (" << next_len1 << ") стало: " << count1 << "*2 + " << count2 << " = " << next_count1 << std::endl;
        } else {
            std::cout << "Длина " << len1 << " ЧЕТНАЯ" << std::endl;
            std::cout << "Она делится на " << (len1 / 2) << " и " << (len1 - 1) / 2 << "." << std::endl;

            next_len1 = len1 / 2;
            next_count1 = count1;
            next_len2 = (len1 / 2) - 1;
            next_count2 = count1 + count2 * 2;

            std::cout << "Новое количество коротких (" << next_len2 << ") стало: " << count1 << " + " << count2 << "*2 = " << next_count2 << std::endl;
        }

        len1 = next_len1;
        count1 = next_count1;
        len2 = next_len2;
        count2 = next_count2;

        step++;
    }

    return 0;
}