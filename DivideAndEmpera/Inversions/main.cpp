#include <iostream>
#include <vector>
#include "RandomNumber.h"

std::vector<long> MergeSort(const std::vector<long> & arr, long low, long high, int & count);
std::vector<long> Merge(std::vector<long> arr1, std::vector<long> arr2, int & count);
int CountOfInversionsNaive(std::vector<long> & arr);

int main() {
    std::vector<long> arr;
    long sizeOfArr;
    long elem;
    std::cin >> sizeOfArr;
    for (long i = 0; i < sizeOfArr; ++i) {
        std::cin >> elem;
        arr.push_back(elem);
    }

    int count = 0;

    std::cout << "Наивная инверсия: \n";
    std::cout << CountOfInversionsNaive(arr) << std::endl;

    std::vector<long> res = MergeSort(arr, 0, arr.size() - 1, count);

    std::cout << "Слиянская инверсия: \n";
    std::cout << count << std::endl;

    return 0;
}

std::vector<long> MergeSort(const std::vector<long> & arr, long low, long high, int & count) {
    std::vector<long> result;
    if (low < high) {
        long middle = (low + high) / 2;
        result = Merge(MergeSort(arr, low, middle, count), MergeSort(arr, middle + 1, high, count), count);
    } else {
        for (long i = low; i <= high; ++i) {
            result.push_back(arr[i]);
        }
    }
    return result;
}

std::vector<long> Merge(std::vector<long> arr1, std::vector<long> arr2, int & count) {
    std::vector<long> result;
    long i = 0;
    long j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            result.push_back(arr1[i]);
            i++;
        } else {
            count += arr1.size() - i;
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

int CountOfInversionsNaive(std::vector<long> & arr) {
    long result = 0;
    for (long i = 0; i < arr.size() - 1; ++i) {
        for (long j = i + 1; j < arr.size(); ++j) {
            if (arr[i] > arr[j]) {
                result++;
            }
        }
    }

    return result;
}
