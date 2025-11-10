#include <iostream>
using namespace std;

int main() {
    string bright_blue = "\033[104m";    // синий
    string bright_red = "\033[101m";     // красный
    string bright_white = "\033[107m";   // белый
    string reset = "\033[0m";            // сброс

    for (int i = 0; i < 6; i++) {
        cout << bright_blue << "  * * * * * * * *  " << reset;
        cout << (i % 2 == 0 ? bright_red : bright_white) << "                              " << reset << endl;
    }

    for (int i = 6; i < 13; i++) {
        cout << (i % 2 == 0 ? bright_red : bright_white) << "                                                 " << reset << endl;
    }

    return 0;
}
