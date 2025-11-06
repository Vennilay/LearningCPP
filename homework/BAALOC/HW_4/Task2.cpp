#include <iostream>

std::string generateLinesWithStars() {
    std::string line;

    for (int row = 0; row < 6; row++) {
        if (row % 2 == 0) {
            for (int star = 0; star < 15; star++) {
                if (star % 2 == 0) {
                    line += "⭐";
                } else {
                    line += "🟦";
                }
            }

            line += "🟦";
            for (int sym = 0; sym < 15; sym++) {
                line += "🟥";
            }

        } else {
            for (int star = 0; star < 16; star++) {
                if (star % 2 == 0) {
                    line += "🟦";
                } else {
                    line += "⭐";
                }
            }

            for (int sym = 0; sym < 15; sym++) {
                line += "⬜";
            }
        }
        line += "\n";
    }
    return line;
}

std::string generateLines() {
    std::string line;
    for (int row = 0; row < 7; row++) {
        if (row % 2 == 0) {
            for (int sym = 0; sym < 31; sym++) {
                line += "🟥";
            }
        }

        line += "\n";
        if (row % 2 == 0) {
            for (int sym = 0; sym < 31; sym++) {
                line += "⬜";
            }
        }
    }
    return line;
}

int main() {
    std::string flag;
    flag = generateLinesWithStars() + generateLines();
    std::cout << flag << std::endl;
}
