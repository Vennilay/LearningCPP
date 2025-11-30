#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ifstream fa("/Users/lkzz/CLionProjects/untitled/5.9A.txt");
    ifstream fb("/Users/lkzz/CLionProjects/untitled/5.9B.txt");

    vector<int> numbers;
    int num;

    while (fa >> num) {
        numbers.push_back(num);
    }
    while (fb >> num) {
        numbers.push_back(num);
    }

    fa.close();
    fb.close();

    sort(numbers.begin(), numbers.end());

    ofstream fc("/Users/lkzz/CLionProjects/untitled/5.9C.txt");

    for (int i = 0; i < numbers.size(); ++i) {
        fc << numbers[i]<<endl;
    }
    fc.close();
    cout<<"Обьединение прошло успешно"<<endl;
    return 0;
}