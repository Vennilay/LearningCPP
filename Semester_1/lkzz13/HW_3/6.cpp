//3.6
#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ofstream writefile("numbers.txt");
    writefile <<"30.4 64 -64 -34 0 0 1";
    writefile.close();
    ifstream readfile("numbers.txt");
    float num;
    float sum=0;
    while (readfile >> num) {
        sum+=num;
    }
    cout <<sum<<endl;
    return 0;
}