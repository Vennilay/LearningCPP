#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

bool is_prime(int n) {
    if (n < 2) return false;
    for (int d = 2; d * d <= n; ++d) {
        if (n % d == 0) return false;
    }
    return true;
}

int gcd(int a, int b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main() {
    const std::string numsFile =
        "/Users/makarleonardov/MyProjects/UniversityProjects/Informatics/LearningCPP/homework/BAALOC/HW_5/numbers.txt";
    const std::string primeFile =
        "/Users/makarleonardov/MyProjects/UniversityProjects/Informatics/LearningCPP/homework/BAALOC/HW_5/primes.txt";
    std::vector<int> numbers;

    std::ifstream inFile(numsFile);
    if (inFile.is_open()) {
        int val;
        while (inFile >> val) numbers.push_back(val);
        inFile.close();
    } else {
        std::ofstream outFile(numsFile);
        std::vector<int> defaultNumbers = {12, 15, 23, 30, 7, 11, 18};
        for (int n : defaultNumbers) outFile << n << " ";
        outFile.close();
        numbers = defaultNumbers;
    }

    std::cout << "Содержимое файла чисел:" << std::endl;
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    int overall_gcd = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i)
        overall_gcd = gcd(overall_gcd, numbers[i]);

    int min_number = *std::min_element(numbers.begin(), numbers.end());
    int min_gcd = 1;
    for (int d = 2; d <= min_number; ++d) {
        bool common = true;
        for (int num : numbers)
            if (num % d != 0) {
                common = false;
                break;
            }
        if (common) {
            min_gcd = d;
            break;
        }
    }

    std::vector<int> primes;
    for (int n : numbers)
        if (is_prime(n)) primes.push_back(n);

    std::ofstream outPrimes(primeFile);
    for (int p : primes) outPrimes << p << " ";
    outPrimes.close();

    std::cout << "Наибольший общий делитель (НОД): " << overall_gcd << std::endl;
    std::cout << "Наименьший общий делитель (кроме 1): " << min_gcd << std::endl;
    std::cout << "Все простые числа: ";
    for (int p : primes) std::cout << p << " ";
    std::cout << std::endl;
    std::cout << "Количество простых чисел: " << primes.size() << std::endl;

    char viewChoice;
    std::cout << "Хотите просмотреть содержимое primes.txt? (y/n): ";
    std::cin >> viewChoice;
    if (viewChoice == 'y' || viewChoice == 'Y') {
        std::ifstream inPrimes(primeFile);
        std::cout << "Содержимое primes.txt:" << std::endl;
        int p;
        while (inPrimes >> p) std::cout << p << " ";
        std::cout << std::endl;
        inPrimes.close();
    }

    return 0;
}
