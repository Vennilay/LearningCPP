#include <iostream>
#include <fstream>

int main() {
    std::ofstream file("../txtfiles/5.3.13.txt");

    if (file.is_open()) {
        file << "Hello World!\n";
        file << "Это пример записи текста в файл.\n";
        
        std::cout << "Файл успешно записан!" << std::endl;
        file.close();
    } else {
        std::cout << "Не удалось создать файл." << std::endl;
    }

    return 0;
}
