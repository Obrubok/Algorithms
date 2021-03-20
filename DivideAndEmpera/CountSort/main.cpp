#include <iostream>
#include <vector>

std::vector<int> CountSort(const std::vector<int> & arr);

int main() {
    int len;
    std::cin >> len;
    int num;
    std::vector<int> numbers;
    std::vector<int> sortedNumbers;
    for (int i = 0; i < len; ++i) {
        std::cin >> num;
        numbers.push_back(num);
    }

    sortedNumbers = CountSort(numbers);

    for (auto & number : sortedNumbers) {
        std::cout << number << " ";
    }

    return 0;
}

std::vector<int> CountSort(const std::vector<int> & arr) {
    const int NUM = 11;
    int digits[NUM] {};
    std::vector<int> result(arr.size(), 0);
    for (int i = 0; i < arr.size(); i++) {
        digits[arr[i]]++;
    }
    for (int i = 1; i < NUM; i++) {
        digits[i] += digits[i - 1];
    }
    for (int i = arr.size() - 1; i >= 0; i--) {
        result[digits[arr[i]] - 1] = arr[i];
        digits[arr[i]]--;
    }

    return result;
}
