#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
using Segment = std::pair<int, int>;
//typedef pair<int, int> Segment;

std::vector<int> get_covering_set(std::vector<Segment> segments);
std::vector<Segment> sortArray(std::vector<Segment> array);
bool comparePairs(Segment a, Segment b);

int main() {
    int segCount;
    std::cout << "Введите кол-во отрезков: ";
    std::cin >> segCount;
    std::vector<Segment> segments(segCount);
    for (auto &s : segments) {
        std::cin >> s.first >> s.second;
    }
    auto points = get_covering_set(segments);
    std::cout << "Размер множества точек: " << points.size() << std::endl;
    for (auto point : points) {
        std::cout << point << " ";
    }
    std::cout << std::endl;
    return 0;
}

std::vector<int> get_covering_set(std::vector<Segment> segments) {
    std::vector<int> result;

    segments = sortArray(segments);

    while (!segments.empty()) {
        Segment firstPair = segments[0];
        result.push_back(segments[0].second);
        segments.erase(segments.cbegin());

        auto iter = segments.cbegin();
        while (iter != segments.cend()) {
            if (firstPair.second >= iter->first) {
                iter = segments.erase(iter);
            } else {
                ++iter;
            }
        }
    }

    return result;
}

std::vector<Segment> sortArray(std::vector<Segment> array) {
    std::sort(array.begin(), array.end(), comparePairs);
    return array;
}

bool comparePairs (Segment a, Segment b) {
    return a.second == b.second ? a.first < b.first : a.second < b.second;
}
