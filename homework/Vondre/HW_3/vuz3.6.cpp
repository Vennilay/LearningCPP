#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::cout<<"Введите 10 чисел через пробел, для записи их в файл: ";
    std::vector<double> numbers;
    double vvod, sum=0, num;

    for (int i = 0; i<10; i++) {
        std::cin>>vvod;
        numbers.push_back(vvod);
    }

    std::ofstream file("files/Vondre/HM_3/task6.txt");

    for (double n : numbers) {
        file << n <<" ";
    }
    file.close();

    std::ifstream from_file("files/Vondre/HM_3/task6.txt");
    while (from_file>>num){
        sum+=num;
    }
    from_file.close();
    std::cout<<"Числа записаны в файл"<<std::endl;
    std::cout<<"Сумма чисел в файле равна "<<sum;
}