#include <iostream>
#include<time.h>// нужно для srand(time(NULL)), чтобы создать случайное число
using namespace std;
void print(int a) {
    cout << a << endl;
};
void print(string a) {
    cout << a << endl;
};

int main()
{

    setlocale(LC_ALL, "RU");

     srand(time(NULL)); 
    cout << 1 + rand() % 100<<"\n";//случайное число до 100
    
    float num1, num2,res;
    
    cout << "enter num1: ";
    cin >> num1;

    cout << "enter num2: ";
    cin >> num2;

    char math;

    cout << "enter math symbol ";
    cin >> math;

    if (math == '+')
    {
        res = num1 + num2;
        print(res);
    }
    else if (math == '-')
    {
        res = num1 - num2;
        print(res);
    }
    else if (math == '*')
    {
        res = num1 * num2;
        print(res);
    }
    else if (math = '/' && num2 != 0)
    {
        res = num1 / num2;
        print(res);
    }
 
    else {
        res = 0;
        print("Делить на ноль нельзя");

    }
    //плохо работатет при делении на 0


    // control+shift+/ 
    //почему не работает ""
    // почему разный результат при делении на 0



    /*switch (math) {

    case '+': res = num1 + num2; break;
    case '-': res = num1 - num2; break;
    case '*': res = num1 * num2; break;
    case '/': res = num1 / num2; break;
    
    default: 
        res = 0; 
        cout << "Error";
        break;
    }
    */





    return 0;

}