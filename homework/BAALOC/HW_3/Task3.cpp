#include <iostream>
#include <string>

void bubbleSort(std::string str) {
    int n = str.length();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (str[j] > str[j + 1]) {
                std::swap(str[j], str[j + 1]);
            }
        }
    }
}

int main() {
    std::string letters = "qwertyuiopasdfghjklzxcvbnmqwerty";

    std::cout << "Исходная строка: " << letters << std::endl;
    bubbleSort(letters);
    std::cout << "Отсортированная строка: " << letters << std::endl;

    return 0;
}
