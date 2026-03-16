#include <iostream>
using namespace std;

class A
{
    private:
    int valueClose;

    public:
    int valueOpen;

    void setValueOpen(int value)
    {
        this->valueOpen = value;
    }
    int getValueOpen()
    {
        return valueOpen;
    }
    void setValueClosed(int value)
    {
        this->valueClose = value;
    }
    int getValueClosed()
    {
        return valueClose;
    }
};

int main()
{
    A a;
    a.setValueClosed(19);
    cout << a.getValueClosed() << endl;
}