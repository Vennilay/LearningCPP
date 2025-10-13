#include <iostream>
#include <iomanip>

int main() {
    std::cout << "|" << std::setw(10) << "x" << "|" << std::setw(10) << "y" << "|" << std::endl;
    std::cout << "-----------------------" << std::endl;
    for (int i = -8; i <= 8; i++) {
        double x = i * 0.5;

        if (x == 1)
            std::cout << "|" << std::setw(10) << x << "|" << std::setw(11) << "Zero dev|" << std::endl;
        else {
            double y = (std::pow(x, 2) - 2 * x + 2) / (x - 1);
            std::cout << "|" << std::setw(10) << x << "|" << std::setw(10) << y << "|" << std::endl;
        }
    }

    return 0;
}
