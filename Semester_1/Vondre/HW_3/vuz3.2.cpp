#include <iostream>
#include <fstream>
#include <cctype>

int main() {
    std::fstream file("files/task2.txt");

    if (!file.is_open()) {
        std::cout<<"Xd";
    }
    std::string content;
    content.assign((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));

    std::string digits="", result;
    for (char c : content) {
        if (isdigit(c)) {
            digits+=c;
            }
        else {
            if (!digits.empty()) {
                result+=digits+" ";
                digits="";
            }
        }
    }
    file.close();
    std::cout<<result+digits;
}