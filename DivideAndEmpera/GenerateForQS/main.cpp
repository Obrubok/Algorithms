#include <iostream>
#include <fstream>
#include "RandomNumber.h"

void GenForCountSort();

int main() {
//    std::string fileName = "../debug-data.txt";
//    std::ofstream file(fileName, std::ios::out);
//    long countOfInts = GetRandomNumberDiap(1, 100);
//    long countOfPoints = GetRandomNumberDiap(1, 20);
//    file << countOfInts << " " << countOfPoints << "\n";
//    long first;
//    long second;
//    for (int i = 0; i < countOfInts; ++i) {
//        first = GetRandomNumberDiap(0, 20);
//        second = GetRandomNumberDiap(first + 1, first + 20);
//        file << first << " " << second << "\n";
//    }
//    long point;
//    for (int i = 0; i < countOfPoints; ++i) {
//        point = GetRandomNumberDiap(0, 40);
//        i != countOfPoints - 1 ? file << point << " " : file << point;
//    }
//    file.close();
    GenForCountSort();

    return 0;
}

void GenForCountSort() {
    std::string fileName = "../debug.txt";
    std::ofstream file(fileName, std::ios::out);
    long countOfElems = GetRandomNumberDiap(500, 1000);
    file << countOfElems << "\n";
    long elem;
    for (int i = 0; i < countOfElems; i++) {
        elem = GetRandomNumberDiap(0, 10);
        i != countOfElems - 1 ? file << elem << " " : file << elem;
    }
    file.close();
}
