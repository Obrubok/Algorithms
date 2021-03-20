#include <iostream>
#include <vector>
#include <string>

int LevenDistBottomUp(std::string &a, std::string &b);
int Difference(char ch1, char ch2);

int main() {
    std::string str1 = "";
    std::string str2 = "";
    std::cin >> str1;
    std::cin >> str2;

    int edDist = LevenDistBottomUp(str1, str2);
    std::cout << edDist;

    return 0;
}

int LevenDistBottomUp(std::string &a, std::string &b) {
    int aSize = a.size();
    int bSize = b.size();
//    if (aSize == 0 || bSize == 0) {
//        return aSize + bSize;
//    }
    std::vector<std::vector<int> > dist(a.size() + 1, std::vector<int>(b.size() + 1, 0));
    for (int i = 0; i <= aSize; i++) {
        dist[i][0] = i;
    }
    for (int j = 0; j <= bSize; j++) {
        dist[0][j] = j;
    }

    for (int i = 1; i <= aSize; i++) {
        for (int j = 1; j <= bSize; j++) {
            int diff = Difference(a[i - 1], b[j - 1]);
            dist[i][j] = std::min(dist[i - 1][j] + 1, std::min(dist[i][j - 1] + 1, dist[i - 1][j - 1] + diff));
        }
    }

    return dist[aSize][bSize];
}

int Difference(char ch1, char ch2) {
    return ch1 == ch2 ? 0 : 1;
}
