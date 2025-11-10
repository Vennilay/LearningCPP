#include <iostream>

int main() {
    for (int i = 0; i<3; i++) {
        std::cout << "\033[44m" <<" * * * * * * * * "<< "\033[41m" << "\t\t\t\t\t\t\t\t\t\t"<< "\033[0m" << std::endl;
        std::cout << "\033[44m" << " * * * * * * * * "<<"\33[107m" << "\t\t\t\t\t\t\t\t\t\t" << "\033[0m" << std::endl;
    }
    for (int i = 0; i<3; i++) {
        std::cout << "\033[41m" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t"<< "\033[0m" << std::endl;
        std::cout << "\033[44m" <<"\33[107m" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << "\033[0m" << std::endl;
    }
}