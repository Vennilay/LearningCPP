
#include <iostream>
#include <deque>
#include <algorithm>
#include <string>


std::string multiply(std::string num1, std::string num2) { //считаю прооизведение по принципу умножения в столбик
    if(num1 == "0" or num2 == "0") {
        return "0";
    }

    int len2 = num2.size();
    int len1 = num1.size();

    std::deque <int> result(len1 + len2, 0);//создаю массив с 0, длинна котрого равна максимальной длине произведения двух числе

    for(int i = len1 - 1; i >= 0; i--) {
        for(int j = len2 - 1; j >= 0; j--) {
            int product = (num1[i] - '0') * (num2[j] - '0');

            int sum = product + result[i + j + 1];

            result[i + j + 1] = sum % 10; //записываю значение в ячейку
            result[i + j] += sum / 10; //если значение в ячейке больше 10, перекидываю десятки в соседнюю
        }
        if (result[0] == 0){
            result.pop_front();
        }
    }

    std::string str_result = "";
    for(int digit : result) {
        str_result += std::to_string(digit);
    }
    return str_result;
}

int main() {
    std::string vvod;
    std::cout << "Введите число, оканчивающееся на 5: ";
    std::cin >> vvod;
    vvod.pop_back(); //убираю последнюю цифру
    int num_1 = stoi(vvod);
    int num_2 = num_1 + 1;
    std::string num1 = std::to_string(num_1);
    std::string num2 = std::to_string(num_2);

    std::string result = multiply(num1, num2);
    result += "25";
    // reverse(result.begin(), result.end());
    // for(int i = 0; i < result.size(); i += 2) {
    //     cout << result[i];
    // }
    std::cout<<result;
}