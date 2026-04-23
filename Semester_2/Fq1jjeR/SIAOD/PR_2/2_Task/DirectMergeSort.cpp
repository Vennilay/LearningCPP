#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;

struct TouristGuide {
    string country;
    string city;
    string hotel;
    string travel_cond;
    string excursion;
    string service;
    int price;
};

ofstream& operator<<(ofstream& os, const TouristGuide& t) {
    os << t.country << "|" << t.city << "|" << t.hotel << "|"
       << t.travel_cond << "|" << t.excursion << "|" << t.service << "|" << t.price << endl;
    return os;
}

ifstream& operator>>(ifstream& is, TouristGuide& t) {
    string temp;
    if (getline(is, t.country, '|')) {
        getline(is, t.city, '|');
        getline(is, t.hotel, '|');
        getline(is, t.travel_cond, '|');
        getline(is, t.excursion, '|');
        getline(is, t.service, '|');
        is >> t.price;
        getline(is, temp);
        return is;
    }
    return is;
}

void generateRandomData(string fileName, int n) {
    ofstream out(fileName);
    vector<string> countries = {"Россия", "Франция", "Италия", "Испания", "Германия",
                                 "Турция", "Египет", "Китай", "Япония", "США"};
    vector<string> cities = {"Москва", "Париж", "Рим", "Мадрид", "Берлин",
                             "Стамбул", "Каир", "Пекин", "Токио", "Нью-Йорк"};
    vector<string> hotels = {"Люкс", "Премиум", "Стандарт", "Эконом", "Делюкс"};
    vector<string> conditions = {"Виза не требуется", "Виза требуется", "Безвизовый"};
    vector<string> excursions = {"Включена", "За доп. плату", "Нет"};
    vector<string> services = {"Завтрак", "Полупансион", "Все включено", "Без питания"};

    random_device rd;
    mt19937 gen(rd());

    for (int i = 0; i < n; i++) {
        TouristGuide t;
        t.country = countries[gen() % countries.size()] + "_" + to_string(gen() % 100);
        t.city = cities[gen() % cities.size()] + "_" + to_string(gen() % 50);
        t.hotel = hotels[gen() % hotels.size()];
        t.travel_cond = conditions[gen() % conditions.size()];
        t.excursion = excursions[gen() % excursions.size()];
        t.service = services[gen() % services.size()];
        t.price = 100 + (gen() % 5000);
        out << t;
    }
    out.close();
}

bool isSorted(string fileName) {
    ifstream file(fileName);
    TouristGuide prev, curr;
    if (!(file >> prev)) return true;
    while (file >> curr) {
        if (prev.country > curr.country) {
            file.close();
            return false;
        }
        prev = curr;
    }
    file.close();
    return true;
}

void split(string fileA, string fileB, string fileC, int k) {
    ifstream A(fileA);
    ofstream B(fileB), C(fileC);
    TouristGuide t;
    int count = 0;
    while (A >> t) {
        if ((count / k) % 2 == 0)
            B << t;
        else
            C << t;
        count++;
    }
    A.close(); B.close(); C.close();
}

void merge(string fileA, string fileB, string fileC, int k) {
    ofstream A(fileA);
    ifstream B(fileB), C(fileC);
    TouristGuide tB, tC;
    bool hasB = bool(B >> tB);
    bool hasC = bool(C >> tC);
    while (hasB && hasC) {
        int i = 0, j = 0;
        while (i < k && hasB && j < k && hasC) {
            if (tB.country <= tC.country) {
                A << tB;
                hasB = bool(B >> tB);
                i++;
            } else {
                A << tC;
                hasC = bool(C >> tC);
                j++;
            }
        }
        while (i < k && hasB) {
            A << tB;
            hasB = bool(B >> tB);
            i++;
        }
        while (j < k && hasC) {
            A << tC;
            hasC = bool(C >> tC);
            j++;
        }
    }
    while (hasB) {
        A << tB;
        hasB = bool(B >> tB);
    }
    while (hasC) {
        A << tC;
        hasC = bool(C >> tC);
    }
    A.close(); B.close(); C.close();
}

void directMergeSort(string fileName, int n, long long &timeMs) {
    auto start = chrono::high_resolution_clock::now();
    int k = 1;
    while (k < n) {
        split(fileName, "B.txt", "C.txt", k);
        merge(fileName, "B.txt", "C.txt", k);
        k *= 2;
    }
    auto end = chrono::high_resolution_clock::now();
    timeMs = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

int main() {
    vector<int> recordCounts = {8, 16, 32};

    cout << "Записей\tВремя (мс)" << endl;
    for (int n : recordCounts) {
        string fileName = "data_" + to_string(n) + ".txt";
        generateRandomData(fileName, n);
        long long timeMs = 0;
        directMergeSort(fileName, n, timeMs);
        cout << n << "\t" << timeMs << endl;
    }

    return 0;
}