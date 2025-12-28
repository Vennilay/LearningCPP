#include <iostream>

int main() {
    int numbers[] = {64, 34, 25, 12, 22};
    int size = 5;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    std::cout << "Результат: ";
    for (int i = 0; i < size; i++)
        std::cout << numbers[i] << " ";

    return 0;
}

// #include <iostream>
// #include <string>
//
// int main() {
//     std::string text = "wdjejkfgerwgkr";
//     int size = text.length();
//
//     for (int i = 0; i < size - 1; i++) {
//         for (int j = 0; j < size - i - 1; j++) {
//             if (text[j] > text[j + 1]) {
//                 char temp = text[j];
//                 text[j] = text[j + 1];
//                 text[j + 1] = temp;
//             }
//         }
//     }
//
//     std::cout << "Исходная: wdjejkfgerwgkr\n";
//     std::cout << "Результат: " << text;
//
//     return 0;
// }


#include <iostream>

// int main() {
//     double grades[] = {3.5, 4.8, 2.1, 3.9, 1.7};
//     int size = 5;
//
//     for (int i = 0; i < size - 1; i++) {
//         for (int j = 0; j < size - i - 1; j++) {
//             if (grades[j] > grades[j + 1]) {
//                 double temp = grades[j];
//                 grades[j] = grades[j + 1];
//                 grades[j + 1] = temp;
//             }
//         }
//     }
//
//     std::cout << "Результат: ";
//     for (int i = 0; i < size; i++)
//         std::cout << grades[i] << " ";
//
//     return 0;
// }


