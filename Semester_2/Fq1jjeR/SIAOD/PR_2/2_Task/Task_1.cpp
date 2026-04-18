#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;

// Структура «Туристическое предложение»
struct TouristOffer {
    string country;
    string city;
    string accommodation;
    string transport;
    string excursions;
    string service;
    float price;

    // Запись объекта в текстовый файл (в одну строку)
    void writeToFile(ofstream& out) const {
        out << country << " " << city << " " << accommodation << " "
            << transport << " " << excursions << " " << service << " " << price << endl;
    }

    // Чтение объекта из текстового файла
    bool readFromFile(ifstream& in) {
        return (in >> country >> city >> accommodation >> transport >> excursions >> service >> price) ? true : false;
    }
};

// Сравнение по стране
bool lessThan(const TouristOffer& a, const TouristOffer& b) {
    return a.country < b.country;
}

// Создание тестового файла (текстовый формат)
void createTestFile(const string& filename, int count) {
    ofstream out(filename);
    const char* countries[] = {"Russia", "Turkey", "Egypt", "Thailand", "France", "Italy", "Spain", "USA", "China", "Japan", "Germany", "Greece", "India", "Brazil", "Australia", "Mexico"};

    for (int i = 0; i < count; ++i) {
        TouristOffer offer;
        offer.country = countries[(count - i) % 16];
        offer.city = "City";
        offer.accommodation = "Hotel";
        offer.transport = "Plane";
        offer.excursions = "Full";
        offer.service = "VIP";
        offer.price = 1000.0f + i * 10;
        offer.writeToFile(out);
    }
    out.close();
}

// Фаза разделения
void splitFile(const string& fileA, const string& fileB, const string& fileC, int seriesSize) {
    ifstream in(fileA);
    ofstream outB(fileB);
    ofstream outC(fileC);

    TouristOffer rec;
    int count = 0;
    while (rec.readFromFile(in)) {
        if ((count / seriesSize) % 2 == 0) rec.writeToFile(outB);
        else rec.writeToFile(outC);
        count++;
    }
    in.close(); outB.close(); outC.close();
}

// Фаза слияния
void mergeFiles(const string& fileA, const string& fileB, const string& fileC, int seriesSize) {
    ifstream inB(fileB);
    ifstream inC(fileC);
    ofstream outA(fileA);

    TouristOffer recB, recC;
    bool hasB = recB.readFromFile(inB);
    bool hasC = recC.readFromFile(inC);

    while (hasB || hasC) {
        int countB = 0, countC = 0;
        while (countB < seriesSize && countC < seriesSize && hasB && hasC) {
            if (lessThan(recB, recC)) {
                recB.writeToFile(outA);
                hasB = recB.readFromFile(inB);
                countB++;
            } else {
                recC.writeToFile(outA);
                hasC = recC.readFromFile(inC);
                countC++;
            }
        }
        while (countB < seriesSize && hasB) {
            recB.writeToFile(outA);
            hasB = recB.readFromFile(inB);
            countB++;
        }
        while (countC < seriesSize && hasC) {
            recC.writeToFile(outA);
            hasC = recC.readFromFile(inC);
            countC++;
        }
    }
    inB.close(); inC.close(); outA.close();
}

void directMergeSort(const string& filename) {
    int seriesSize = 1;

    // Подсчет количества записей в текстовом файле
    int fileSize = 0;
    ifstream in(filename);
    TouristOffer temp;
    while (temp.readFromFile(in)) fileSize++;
    in.close();

    string fileB = "B.txt", fileC = "C.txt";
    while (seriesSize < fileSize) {
        splitFile(filename, fileB, fileC, seriesSize);
        mergeFiles(filename, fileB, fileC, seriesSize);
        seriesSize *= 2;
    }
}

int main() {
    const string dataFile = "offers.txt";
    vector<int> sizes = {8, 16, 32};

    cout << "Результаты прямого слияния:\n";
    cout << "Записей\tВремя (мс)\n";

    for (int n : sizes) {
        createTestFile(dataFile, n);

        auto start = chrono::high_resolution_clock::now();
        directMergeSort(dataFile);
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << n << "\t" << duration.count() / 1000.0 << " мс\n";
    }

    return 0;
}
