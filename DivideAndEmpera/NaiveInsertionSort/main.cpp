#include <iostream>
#include <ctime>
#include <random>
#include <vector>

long getRandomNumberDiap(long a, long b);
long getRandomNumberDiapNew(long a, long b);
void InsertSort(std::vector<int> & numbers);

int main() {
    std::vector<int> arr;
    int count, a, b;
    std::cout << "Введите размер массива: ";
    std::cin >> count;
    std::cout << "Введите диапазон: ";
    std::cin >> a >> b;
    std::cout << "Неотсортированный массив: " << std::endl;
    unsigned int seed = static_cast<unsigned int>(time(0));
    srand(seed);
    for (int i = 0; i < count; i++) {
        arr.push_back(getRandomNumberDiapNew(a, b));
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Отсортированный массив: " << std::endl;
    InsertSort(arr);
    for (int i = 0; i < count; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}

long getRandomNumberDiapNew(long a, long b) {
    std::random_device rd;
    std::mt19937_64 mersenne(rd());
    std::uniform_int_distribution<> distribution(a, b);
    return distribution(mersenne);
}

long getRandomNumberDiap(long a, long b) {
    return a + rand() % (b - a + 1);
}

void InsertSort(std::vector<int> &numbers) {
    for (int i = 1; i < numbers.size(); ++i) {
        int j = i;
        while (j > 0 && numbers[j] < numbers[j - 1]) {
            std::swap(numbers[j], numbers[j - 1]);
            j--;
        }
    }
}
