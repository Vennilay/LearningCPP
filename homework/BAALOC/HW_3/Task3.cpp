#include <iostream>

int main() {
    std::string alph = "abcdefghijklmnopqrstuvwxyz";
    std::string line = "qweasdzxcvbnmrewqplmoknijuhyt";
    std::string newLine;
    int last_index = 0;

    while (line.data()) {
        for (char sym : line) {
            if (alph.find(sym) == last_index) {
                newLine += sym;
                last_index += 1;
                std::cout << newLine << std::endl;
                line.erase(sym, 1);
            }
        }
    }


    std::cout << newLine << std::endl;
    return 0;
}
