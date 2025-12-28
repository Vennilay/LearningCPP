#include <iostream>
#include <algorithm>

int main(){
    std::string proverka = "qwertyuiopasdfghjklzxcvbnm";
    std::string vvod;
    std::cout<<"Введите строку из 30 букв: ";
    std::cin>>vvod;
    if (vvod.size() != 30) std::cout<<"Длинна строки отличается от необходимой";

    else {
        int k = 0;
        for (char c : vvod){
            if (proverka.find(c)!=std::string::npos) k+=1;
        }
        if (k!=30) std::cout<<"В строке есть посторонние символы";
        else {
            std::sort(vvod.begin(), vvod.end());
            std::cout<<vvod;
        }
    }
}