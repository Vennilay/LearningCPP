#include <iostream>

int main() {
    std::cout << "Это тестовый файл, чтобы СОСАТЬ !" << std::endl;

    return 0;
}cmake_minimum_required(VERSION 4.1)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        programm.cpp)
