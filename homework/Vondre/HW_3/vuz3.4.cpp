#include <iostream>
#include <set>

int main() {
    std::cout << "Введите натуральное число: ";
    int vvod;
    std::cin >> vvod;
    if (vvod < 1) std::cout << "Это число не является натуральным";

    else {
        std::set<int> primes;
        for (int i = 2; i <= vvod; i++) primes.insert(i);

        for (int i = 2; i * i <= vvod; i++) {
            for (int j = i * i; j <= vvod; j+=i) {
                primes.erase(j);
            }

        }
        std::cout<<"Вот простые числа до "<<vvod<<std::endl;
        for (int n: primes) {
            std::cout<<n<<" ";
        }
    }
}

