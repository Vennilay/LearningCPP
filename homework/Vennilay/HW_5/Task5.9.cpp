#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream fa("txtfiles/A.txt");
    std::ifstream fb("txtfiles/B.txt");

    if (!fa) {
        std::cerr << "Не удалось открыть файл A.txt\n";
        return 1;
    }
    if (!fb) {
        std::cerr << "Не удалось открыть файл B.txt\n";
        return 1;
    }

    std::vector<int> nums;
    int x;

    while (fa >> x) {
        nums.push_back(x);
    }
    while (fb >> x) {
        nums.push_back(x);
    }

    fa.close();
    fb.close();

    if (nums.empty()) {
        std::cout << "Оба файла пустые, объединять нечего.\n";
        return 0;
    }

    std::sort(nums.begin(), nums.end());

    std::ofstream fc("txtfiles/C.txt");
    if (!fc) {
        std::cerr << "Не удалось открыть файл C.txt для записи\n";
        return 1;
    }

    for (std::size_t i = 0; i < nums.size(); ++i) {
        fc << nums[i];
        if (i + 1 < nums.size()) {
            fc << ' ';
        }
    }
    fc << '\n';
    fc.close();

    std::cout << "Файл C.txt создан, все числа отсортированы по возрастанию.\n";
    return 0;
}
