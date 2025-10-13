#include <iostream>
#include <iomanip>
#include <string>

int main() {
    double x = -4.0;

    std::cout << "┌──────────┬────────────────────┐" << std::endl;

    std::cout << "│" << std::setw(10) << "x"
              << "│" << std::setw(20) << "f(x)" << "│" << std::endl;

    std::cout << "├──────────┼────────────────────┤" << std::endl;

    while (x <= 4.0) {
        std::cout << "│" << std::setw(10) << x << "│";

        if (x - 1.0 == 0.0) {
            std::cout << std::setw(26) << "НЕЛЬЗЯ" << "│" << std::endl;
        } else {
            std::cout << std::setw(20) << (x*x - 2*x + 2) / (x - 1) << "│" << std::endl;
        }
        x += 0.5;
    }

    std::cout << "└──────────┴────────────────────┘" << std::endl;

    return 0;
}
