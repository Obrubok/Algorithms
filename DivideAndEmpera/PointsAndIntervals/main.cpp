#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <ios>
#include <algorithm>
#include "RandomNumber.h"

using PAIR = std::pair<long, long>;

enum PointType {
    LEFT = -1,
    POINT = 0,
    RIGHT = 1
};

struct Border {
    long point;
    PointType type;
    long position;

    Border(const long point, const PointType type, const long position)
        : point(point)
        , type(type)
        , position(position)
    {}
};

long NaiveIntExistsPoint(std::vector<PAIR> & arr, long point);
void BetterIntExistsPoint(std::vector<Border> & arr, std::vector<long> & answer);
void GetData(std::istream & inputs, std::vector<PAIR> & intervals, std::vector<long> & points);
void GetData2(std::istream & inputs, std::vector<Border> & arr);

int main() {
    std::ios_base::sync_with_stdio(false);
//    long countOfIntervals;
//    long countOfPoints;
//    std::cin >> countOfIntervals >> countOfPoints;
//    std::vector<PAIR> arr;
//    long first, second;
//    for (int i = 0; i < countOfIntervals; ++i) {
//        std::cin >> first >> second;
//        arr.push_back(std::make_pair(first, second));
//    }
//    std::string strOfPoints;
//    std::vector<long> points;
//    std::cin.ignore();
//    long point;
//    for (int i = 0; i < countOfPoints; ++i) {
//        std::cin >> point;
//        points.push_back(point);
//    }

    std::vector<PAIR> intervals;
    std::vector<long> points;
    std::vector<Border> arr;
    std::string fileName = "/home/alexey/proging/C++/DivideAndEmpera/NaiveInsertionSort/debug-data3.txt";
    std::ifstream data(fileName);

    GetData(data, intervals, points);
    data.seekg(0);
    GetData2(data, arr);

    data.close();

    std::vector<long> answer(points.size(), -1);
    std::vector<long> countOfPointsInInt;

    std::sort(arr.begin(), arr.end(), [](const Border &left, const Border &right) {
        return (left.point == right.point) ?  left.type < right.type : left.point < right.point;
    });

    for (int i = 0; i < points.size(); ++i) {
        countOfPointsInInt.push_back(NaiveIntExistsPoint(intervals, points[i]));
    }

    for (int i = 0; i < countOfPointsInInt.size(); ++i) {
        std::cout << countOfPointsInInt[i] << " ";
    }

    std::cout << std::endl;

    BetterIntExistsPoint(arr, answer);

    for (int i = 0; i < answer.size(); ++i) {
        std::cout << answer[i] << " ";
    }

    return 0;
}

long NaiveIntExistsPoint(std::vector<PAIR> &arr, long point) {
    long result = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (point >= arr[i].first && point <= arr[i].second) {
            result++;
        }
    }

    return result;
}

void BetterIntExistsPoint(std::vector<Border> & arr, std::vector<long> & answer) {
    for (int i = 0, cur = 0; i < arr.size(); ++i) {
        if (arr[i].type == LEFT) {
            cur++;
        } else if (arr[i].type == RIGHT) {
            cur--;
        } else {
            answer[arr[i].position] = cur;
        }
    }
}

void GetData(std::istream & inputs, std::vector<PAIR> & intervals, std::vector<long> & points) {
    long countOfItervals;
    long countOfPoints;
    std::istringstream iss;
    std::string str;
    std::getline(inputs, str, '\n');
    iss.str(str);
    iss >> countOfItervals >> countOfPoints;
    iss.clear();
    long first;
    long second;
    long point;
    for (long i = 0; i < countOfItervals; i++) {
        std::getline(inputs, str);
        iss.str(str);
        iss >> first >> second;
        intervals.push_back(std::make_pair(first, second));
        iss.clear();
    }
    std::getline(inputs, str, '\n');
    iss.str(str);
    for (int i = 0; i < countOfPoints; ++i) {
        iss >> point;
        points.push_back(point);
        iss.clear();
    }
}

void GetData2(std::istream &inputs, std::vector<Border> & arr) {
    long countOfItervals;
    long countOfPoints;
    std::istringstream iss;
    std::string str;
    std::getline(inputs, str, '\n');
    iss.str(str);
    iss >> countOfItervals >> countOfPoints;
    iss.clear();
    long point;
    long first;
    long second;
    for (long i = 0; i < countOfItervals; i++) {
        std::getline(inputs, str);
        iss.str(str);
        iss >> first >> second;
        arr.push_back(Border(first, LEFT, -1));
        arr.push_back(Border(second, RIGHT, -1));
        iss.clear();
    }
    std::getline(inputs, str, '\n');
    iss.str(str);
    for (int i = 0; i < countOfPoints; ++i) {
        iss >> point;
        arr.push_back(Border(point, POINT, i));
        iss.clear();
    }
}
