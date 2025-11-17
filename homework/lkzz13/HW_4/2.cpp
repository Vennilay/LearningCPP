/*🟥🟦⬜⭐*/
#include <iostream>
using namespace std;

int main() {
    for (int i=0; i<13;i++) {
        for (int j=0;j<32;j++) {
            if (i<6) {
                if (i%2==0) {
                    if (j<17) {
                        if (j%2==0) {
                            cout<<"⭐";
                        }else {
                            cout<<"🟦";
                        }
                    }else {
                        cout<<"🟥";
                    }
                }else {
                    if (j<17) {
                        if (j%2==0) {
                            cout<<"⭐";
                        }else {
                            cout<<"🟦";
                        }
                    }else {
                        cout<<"⬜";
                    }
                }

            }else {
                if (i%2==0) {
                    cout<<"🟥";
                }else {
                    cout<<"⬜";
                }
            }
        }
        cout<<endl;
    }
}