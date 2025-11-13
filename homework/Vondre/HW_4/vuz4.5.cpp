//Гномья сортировка
#include <iostream>
#include <vector>

void gnomeSort(std::vector<int>& arr) {
    int pos = 0;
    int n = arr.size();

    while (pos < n) {
        if (pos == 0 or arr[pos] >= arr[pos - 1]) {
            pos++;
        } else {
            std::swap(arr[pos], arr[pos - 1]);
            pos--;
        }
    }
}

int main() {
    int n;
    std::cout << "Введите количество элементов: ";
    std::cin >> n;

    std::vector<int> data(n);
    std::cout << "Введите " << n << " элементов через пробел:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> data[i];
    }

    gnomeSort(data);

    std::cout << "Отсортированный массив: ";
    for (int x : data) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
