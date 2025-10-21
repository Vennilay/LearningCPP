#include <fstream>
#include <iostream>
#include <iterator>

int main() {
    std::ifstream file("./files/Vondre/HM_3/task1.txt");

    if (file.is_open()){
        std::string content;
        content.assign((std::istreambuf_iterator<char>(file)),(std::istreambuf_iterator<char>()));
        std::cout << "Содержимое файла:\n" << content << std::endl;
        file.close();

    }
    else {
        std::cout<<"Что-то пошло не так";
    }
}