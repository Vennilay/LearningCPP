#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    for (double y = 1.1; y >= -1.1; y -= 0.05)
    {
        for (double x = -3.1; x <= 3.1; x += 0.05)
        {
            if (fabs(y) < 0.01)
            {
                cout << "-";
            }
            else if (fabs(x) < 0.01)
            {
                cout << "|";
            }
            else if (fabs(y - sin(x)) < 0.025)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
