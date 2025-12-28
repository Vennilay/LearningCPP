#include <iostream>
#include <fstream>

std::vector<int> read(const std::string& f) {
    std::ifstream in(f);
    std::vector<int> v;
    int x;

    while (in >> x) {
        v.push_back(x);
    }

    return v;
}

void show(const std::vector<int>& v) {
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int gcd(int a, int b) { // наибольший общий делитель, алгоритм Евклида
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int overall_gcd(const std::vector<int>& v) {
    int res = v[0];

    for (size_t i = 1; i < v.size(); ++i) {
        res = gcd(res, v[i]);
    }

    return res;
}

int min_div(const std::vector<int>& v) {
    int mn = *std::min_element(v.begin(), v.end());

    for (int d = 2; d <= mn; ++d) {
        bool ok = true;

        for (int x : v) {
            if (x % d != 0) {
                ok = false;
                break;
            }
        }

        if (ok) {
            return d;
        }
    }

    return 1;
}

bool prime(int n) {
    if (n < 2) {
        return false;
    }

    for (int d = 2; d * d <= n; ++d) {
        if (n % d == 0) {
            return false;
        }
    }

    return true;
}

std::vector<int> primes(const std::vector<int>& v) {
    std::vector<int> p;

    for (int x : v) {
        if (prime(x)) {
            p.push_back(x);
        }
    }

    return p;
}

void write(const std::vector<int>& v, const std::string& f) {
    std::ofstream out(f);

    for (int x : v) {
        out << x << " ";
    }
}

int main() {
    const std::string numsFile =
        "files/numbers.txt";

    const std::string primesFile =
        "files/primes.txt";

    std::vector<int> v = read(numsFile);

    if (v.empty()) {
        std::cout << "Файл пуст или не найден\n";
        return 1;
    }

    std::cout << "Содержимое:\n";
    show(v);

    std::cout << "НОД: " << overall_gcd(v) << std::endl;
    std::cout << "Наименьший общий делитель: " << min_div(v) << std::endl;

    std::vector<int> p = primes(v);

    std::cout << "Простые: ";
    show(p);

    std::cout << "Количество простых: " << p.size() << std::endl;

    write(p, primesFile);

    char ans;
    std::cout << "Показать primes.txt? (y/n): ";
    std::cin >> ans;

    if (ans == 'y' || ans == 'Y') {
        std::vector<int> pv = read(primesFile);
        show(pv);
    }

    return 0;
}
