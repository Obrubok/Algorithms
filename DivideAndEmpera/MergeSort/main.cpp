#include <iostream>
#include <vector>
#include "RandomNumber.h"
#include <array>
#include <algorithm>

std::vector<int> MergeSort(const std::vector<int> & arr, int low, int high);
std::vector<int> Merge(std::vector<int> arr1, std::vector<int> arr2);

int main() {
    // ТЕСТ MERGE
//    std::vector<int> arr1;
//    std::vector<int> arr2;
//    for (int i = 0; i < 10; ++i) {
//        arr1.push_back(getRandomNumberDiap(-50, 50));
//    }
//    for (int i = 0; i < 10; ++i) {
//        arr2.push_back(getRandomNumberDiap(-50, 50));
//    }
//    std::sort(arr1.begin(), arr1.end());
//    std::sort(arr2.begin(), arr2.end());
//
//    std::cout << "Первый массив: " << std::endl;
//    for (int i = 0; i < 10; ++i) {
//        std::cout << arr1[i] << " ";
//    }
//    std::cout << "\nВторой массив: " << std::endl;
//    for (int i = 0; i < 10; ++i) {
//        std::cout << arr2[i] << " ";
//    }
//    std::cout << std::endl;
//
//    std::cout << "Результат: \n";
//    std::vector<int> res = Merge(arr1, arr2);
//    for (int i = 0; i < res.size(); ++i) {
//        std::cout << res[i] << " ";
//    }
    // ТЕСТ ОКОНЧЕН

    std::vector<int> arr;
    std::vector<int> res;
    for (int i = 0; i < 10; ++i) {
        arr.push_back(getRandomNumberDiap(-50, 50));
    }
//    arr.push_back(-32);
//    arr.push_back(29);
//    arr.push_back(13);
//    arr.push_back(-33);
//    arr.push_back(23);
//    arr.push_back(-29);
//    arr.push_back(41);
//    arr.push_back(-37);
//    arr.push_back(28);
//    arr.push_back(40);

    std::cout << "Массив: " << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    res = MergeSort(arr, 0, arr.size()-1);
    std::cout << "Результат: \n";
    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i] << " ";
    }

    return 0;
}

std::vector<int> MergeSort(const std::vector<int> & arr, int low, int high) {
    std::vector<int> result;
    if (low < high) {
        int middle = (low + high) / 2;
        result = Merge(MergeSort(arr, low, middle), MergeSort(arr, middle + 1, high));
    } else {
        for (int i = low; i <= high; ++i) {
            result.push_back(arr[i]);
        }
    }
    return result;
}

std::vector<int> Merge(std::vector<int> arr1, std::vector<int> arr2) {
    std::vector<int> result;
    int i = 0;
    int j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            result.push_back(arr1[i]);
            i++;
        } else {
            result.push_back(arr2[j]);
            j++;
        }
    }
    if (i < arr1.size()) {
        for (;i < arr1.size(); i++) {
            result.push_back(arr1[i]);
        }
    } else {
        for (;j < arr2.size(); j++) {
            result.push_back(arr2[j]);
        }
    }

    return result;
}
