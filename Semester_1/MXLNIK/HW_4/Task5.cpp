#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;

void insertion_sort(vector<int>& array)
{
    int n = array.size();
    for (int i = 1; i < n; i++)
    {
        int key = array[i]; // берём элемент для вставки
        int j = i - 1;

        // сдвигаем вправо элементы, которые больше key
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key; // вставляем элемент на правильную позицию
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<int> array = { 5, 2, 7, 4, 6, 1, 3 };
    insertion_sort(array);

    cout << "Отсортированный массив: ";
    for (int i : array)
    {
        cout << i << " ";
    }

    return 0;
}
