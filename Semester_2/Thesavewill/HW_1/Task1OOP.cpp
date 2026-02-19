#include <iostream>

using namespace std;

double fToC(int f = 0);
double avarageTemp(const double tempC[], int n);

int main(){
    int n = 0;
    cin>>n;

    if(n < 7 || n > 30 ){
        cout << "n is wrong" << endl;
        return (0);
    }

    double tempC[n];
    for (int i = 0; i < n; i++){
        int tempF = 0;
        cin >> tempF;
        tempC[i] = fToC(tempF);
    }

    double avgTemp = avarageTemp(tempC, n);
    cout<<"Temperature data: ";

    for (int i = 0; i < n;i++){
        cout<<tempC[i];
        if (i != n - 1) {
            cout<<" ";
        }
    }

    cout<< "\nAvarage temperature: "<<avgTemp;
    return (0);
}

double fToC(int f ){
    return ((double)f-32)*(5.0/9.0);
}
double avarageTemp (const double tempC[],int n){
    double sum = 0;
    for (int i = 0; i < n; i++){
        sum += tempC[i];
    }
    return sum /(double)n;
}
