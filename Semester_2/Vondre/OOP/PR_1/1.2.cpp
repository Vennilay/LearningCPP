#include <iostream>
using namespace std;

class Class
{
    public:
    int valueOpen;

    private:
    int valueClose;

    public:
    void setValueClose(int value)
    {
        this->valueClose = value;
    }
    int getValueClose()
    {
        return valueClose;
    }

    void changeAllValues() {
        if (valueOpen % 2 == 0) {
            valueOpen /= 2;
        }
        else{
            valueOpen *= 2;
        }
        if (valueClose % 2 == 0) {
            valueClose /= 2;
        }
        else{
            valueClose *= 2;
        }
    }
};

int main()
{
    Class obj;
    int a,b;
    cin >> a >> b;

    obj.valueOpen = a;
    obj.setValueClose(b);

    obj.changeAllValues();

    cout << obj.valueOpen << endl;
    cout << obj.getValueClose() << endl;
}