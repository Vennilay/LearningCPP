#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream in("text.txt");
    string line;
    int count = 0;

    while (getline(in, line)) {
        if (!line.empty()) {
            bool sorted = true;
            for (size_t i = 1; i < line.length(); i++) {
                if (line[i] < line[i - 1]) {
                    sorted = false;
                    break;
                }
            }
            if (sorted) {
                count++;
            }
        }
    }

    in.close();

    cout<< "Непустых отсортированных строк - " <<count<<endl;

    return 0;
}