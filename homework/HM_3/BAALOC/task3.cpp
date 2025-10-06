#include <iostream>

int main() {
    const std::string alph = "abcdefghijklmnopqrstuvwxyz";
    std::string line = "qweasdzxcvbnmrewqplmoknijuhyt";

    for (int i = 0; i < line.size(); i++) {
        std::cout << line[i];
    }

    return 0;
}