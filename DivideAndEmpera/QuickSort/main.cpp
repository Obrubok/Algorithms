#include <iostream>
#include <vector>
#include "RandomNumber.h"

void QuickSort(std::vector<long> & arr, long low, long high);
long Partition(std::vector<long> & arr, long low, long high);

int main() {
    std::vector<long> arr;
    for (int i = 0; i < 10; ++i) {
        long elem = GetRandomNumberDiap(-50, 50);
        arr.push_back(elem);
    }

    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }

    std::cout << "\n";

    QuickSort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}

void QuickSort(std::vector<long> & arr, long low, long high) {
    if (low >= high) {
        return;
    }
    long middle = Partition(arr, low, high);
    QuickSort(arr, low, middle - 1);
    QuickSort(arr, middle + 1, high) ;
}

long Partition(std::vector<long> & arr, long low, long high) {
    long randPivotIndex = GetRandomNumberDiap(low, high);
    std::swap(arr[low], arr[randPivotIndex]);
    long x = arr[low];
    long j = low;
    for (int i = low + 1; i <= high ; ++i) {
        if (arr[i] <= x) {
            j++;
            std::swap(arr[j], arr[i]);
        }
    }
    std::swap(arr[low], arr[j]);

    return j;
}
