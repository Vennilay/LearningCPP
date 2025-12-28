#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream FileA("../files/5.5.9A.txt");
    std::ifstream FileB("../files/5.5.9B.txt");

    std::vector<int> nums;
    int x;

    while (FileA >> x) {
        nums.push_back(x);
    }
    while (FileB >> x) {
        nums.push_back(x);
    }

    std::sort(nums.begin(), nums.end());

    std::ofstream FileC("../files/5.5.9C.txt");
    for (int num : nums) {
        FileC << num << ' ';
    }

    std::cout << "Файл C.txt создан, все числа отсортированы.\n";

    return 0;
}
