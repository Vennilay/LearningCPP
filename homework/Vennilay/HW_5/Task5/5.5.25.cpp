#include <iostream>
#include <fstream>
#include <string>

bool is_strictly_increasing(const std::string &s) {
    if (s.empty()) {
        return false;
    }
    for (std::size_t i = 1; i < s.size(); ++i) {
        if (!(s[i - 1] < s[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ifstream fin("../txtfiles/5.5.25");
    if (!fin) {
        std::cerr << "Не удалось открыть файл text.txt для чтения\n";
        return 1;
    }

    std::string line;
    int count = 0;

    while (std::getline(fin, line)) {
        if (!line.empty() && is_strictly_increasing(line)) {
            ++count;
        }
    }

    fin.close();

    std::cout << "Число непустых строк с символами по возрастанию: " << count << "\n";

    return 0;
}
