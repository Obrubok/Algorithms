#include <iostream>
#include <vector>
#include <algorithm>

using Segment = std::pair<int, int>;
bool sortBySecond(Segment a, Segment b);

int main() {
    int segCount;
    std::cout << "Введите кол-во отрезков: ";
    std::cin >> segCount;
    std::vector<Segment> segments(segCount);
    std::cout << "Вводите элементы массива: " << std::endl;
    for (auto &s : segments) {
        std::cin >> s.first >> s.second;
    }
    std::sort(segments.begin(), segments.end(), sortBySecond);
    std::cout << "Отсортированный массив: " << std::endl;
    for (auto s : segments) {
        std::cout << s.first << " " << s.second << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

bool sortBySecond(Segment a, Segment b) {
    return a.second == b.second ? a.first < b.first : a.second < b.second;
}
