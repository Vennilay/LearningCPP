#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const int width = 80;
    const int height = 20;
    const double pi=3.14;
    for (int y=height/2;y>=-height/2;y--) {
        for (int x=-width/2;x<=width/2;x++) {
            double y_sin = sin(x/pi);

            int y_screen = (int)(y_sin * (height / 2));

            if (y==0) {
                cout << "-";
            }else if (x==0) {
                cout<<"|";
            } else if (y_screen==y){
                cout<<("*");
            }
            else {
                cout<<" ";
            }
        }
        cout<<endl;
    }


    return 0;
}