#include <iostream>

using namespace std;

double fToC(int f);
double averageTemp(const double arr[], int n);

int main() {
    int n = 0;
    cin >> n;

    if (n < 7 || n > 30) {
        cout << "n is wrong" << endl;
        return 1;
    }

    const int MAX_SIZE = 30;
    double tempC[MAX_SIZE];

    for (int i = 0; i < n; i++) {
        int tempF = 0;
        cin >> tempF;
        tempC[i] = fToC(tempF);
    }

    cout << "Temperature data: ";
    for (int i = 0; i < n; i++) {
        cout << tempC[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;

    double avgTemp = averageTemp(tempC, n);
    cout << "Average temperature: " << avgTemp;

    return 0;
}


double fToC(int f) {
    return (static_cast<double>(f) - 32) * (5.0 / 9.0);
}

double averageTemp(const double arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / static_cast<double>(n);
}