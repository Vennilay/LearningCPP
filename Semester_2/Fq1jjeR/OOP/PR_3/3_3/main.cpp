#include <iostream>
#include <vector>
#include <string>
#include "NetworkStorage.h"

using namespace std;

int main() {
    // 1. Ввести количество устройств
    int n;
    cin >> n;

    // 2. Объявить контейнер указателей на объекты сетевого хранилища
    vector<NetworkStorage*> objects;

    // 3. Ввод данных и динамическое создание объектов
    for (int i = 0; i < n; ++i) {
        string name;
        int speed, capacity;
        cin >> name >> speed >> capacity;
        objects.push_back(new NetworkStorage(name, speed, capacity));
    }

    // 4. Добавить нулевой указатель в контейнер
    objects.push_back(nullptr);

    // 5. Вывести строку Initial state
    cout << "Initial state" << endl;

    // 6. Вывести информацию обо всех элементах контейнера
    for (int i = 0; i < objects.size(); ++i) {
        if (objects[i] != nullptr) {
            objects[i]->printInfo();
        } else {
            cout << "Empty pointer" << endl;
        }
    }

    // 7. Ввести значение минимально допустимой скорости сети
    int min_speed;
    cin >> min_speed;

    // 8. Модификация объектов по условию
    for (int i = 0; i < objects.size(); ++i) {
        if (objects[i] == nullptr) continue;

        if (objects[i]->getSpeed() < min_speed) {
            string curName = objects[i]->getName();
            int curCapacity = objects[i]->getCapacity();

            delete objects[i];
            objects[i] = new NetworkStorage(curName, 2 * min_speed, curCapacity);
        }
    }

    // 9. Вывести строку Modified state
    cout << "Modified state" << endl;

    // 10. Вывести информацию обо всех элементах контейнера после модификации
    for (int i = 0; i < objects.size(); ++i) {
        if (objects[i] != nullptr) {
            objects[i]->printInfo();
        } else {
            cout << "Empty pointer" << endl;
        }
    }

    // 11. Освободить память
    for (int i = 0; i < objects.size(); ++i) {
        if (objects[i] != nullptr) {
            delete objects[i];
        }
    }

    return 0;
}