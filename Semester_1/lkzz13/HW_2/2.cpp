//2.2
#include  <iostream>
#include <cmath>
using namespace std;
int main() {
    double  b,x,y;
    cin >>b >>x >> y;
    if ((b - y > 0) && (b - x >= 0)) {
        cout <<"z = "<< (log(b-y)*sqrt(b-x))<< endl;
    }
    else {
        cout <<"Функция не определена" << endl;
    }
    return 0;
}