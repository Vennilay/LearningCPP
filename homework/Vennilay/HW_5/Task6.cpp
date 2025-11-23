#include <iostream>
#include <vector>

void generate(int pos, std::vector<int> &a, long long &cnt) {
    int n = static_cast<int>(a.size());

    if (pos == n) {
        bool has_fixed_point = false;
        for (int i = 0; i < n; ++i) {
            if (a[i] == i + 1) {
                has_fixed_point = true;
                break;
            }
        }

        if (has_fixed_point) {
            ++cnt;

            for (int x : a) {
                std::cout << x << ' ';
            }
            std::cout << '\n';
        }

        return;
    }

    // for (int i = pos; i < n; ++i) {
    //     std::swap(a[pos], a[i]);
    //     generate(pos + 1, a, cnt);
    //     std::swap(a[pos], a[i]);
    // }
}

int main() {
    int n = 10;
    std::vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }

    long long cnt = 0;
    generate(0, a, cnt);

    std::cout << "n = " << n << ", count = " << cnt << '\n';

    return 0;
}
