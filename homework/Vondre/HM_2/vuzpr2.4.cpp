#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    cout <<setw(5)<< "X"<<setw(10)<<"Y" << endl;
    for(float x = -4; x <= 4; x += 0.5) {
        if(x == 1) {
            cout <<endl<< "При x = 1 функция не существует" << endl<<endl;
        } else cout << setw(5)<<x <<setw(10)<< (pow(x, 2) - 2 * x + 2) / (x - 1) << endl;
    }
}

