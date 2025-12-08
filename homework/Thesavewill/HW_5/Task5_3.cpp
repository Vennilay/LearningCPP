#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;
//9
int main() {

    string path = "C:/Users/Denis/Documents/GitHub/LearningCPP/homework/Thesavewill/HW_5/files/";
    string fileA = path + "A.txt";
    string fileB = path + "B.txt";
    string fileC = path + "C.txt";

    vector<int> numbers;
    int num;

    ifstream inA(fileA);
    while (inA >> num) numbers.push_back(num);
    inA.close();

    ifstream inB(fileB);
    while (inB >> num) numbers.push_back(num);
    inB.close();

    sort(numbers.begin(), numbers.end());
    ofstream outC(fileC);
    for (int n : numbers) outC << n << " ";
    outC.close();

    cout << "Файлы успешно объединены и отсортированы в " << fileC << endl;

    return 0;
}
