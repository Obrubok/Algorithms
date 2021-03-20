#include <iostream>
#include <vector>

int LISBottomUpWOPred(std::vector<int> &, std::vector<int> &);
int LISBottomUp(std::vector<int> &, std::vector<int> &);
std::vector<int> SubseqRecovery(std::vector<int> &dist, int max);
std::vector<int> SunseqFromIndex(std::vector<int> &arr, std::vector<int> &seqInd);

int main() {
    std::vector<int> arr {7, 2, 1, 3, 8, 4, 9, 1, 2, 6, 5, 9, 3, 8, 1};
    std::vector<int> dist1(arr.size(), -1);
    std::vector<int> dist2(arr.size(), -1);
    int ans1 = LISBottomUpWOPred(arr, dist1);
    int ans2 = LISBottomUp(arr, dist2);

    std::cout << "Без условия: \n";
    std::cout << "Самая длинная посл-ть: " << ans1 << "\n";
    std::cout << "Вектор длин: ";
    for (int i = 0; i < dist1.size(); i++) {
        std::cout << dist1[i] << " ";
    }
    std::cout << "\n";
    std::cout << "С условием: \n";
    std::cout << "Самая длинная посл-ть: " << ans2 << "\n";
    std::cout << "Вектор длин: ";
    for (int i = 0; i < dist2.size(); i++) {
        std::cout << dist2[i] << " ";
    }

    std::cout << "\n";
    std::vector<int> subseqIndexes = SubseqRecovery(dist2, ans2);
    for (int i = 0; i < subseqIndexes.size(); ++i) {
        std::cout << subseqIndexes[i] << " ";
    }

    std::cout << "\n";
    std::vector<int> result = SunseqFromIndex(arr, subseqIndexes);
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }

    return 0;
}

int LISBottomUpWOPred(std::vector<int> &arr, std::vector<int> &dist) {
    size_t size = arr.size();
    for (int i = 0; i < size; i++) {
        dist[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dist[i] = dist[j] + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < size; i++) {
        ans = std::max(ans, dist[i]);
    }

    return ans;
}

int LISBottomUp(std::vector<int> &arr, std::vector<int> &dist) {
    size_t size = arr.size();
    for (int i = 0; i < size; i++) {
        dist[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && (dist[j] + 1) > dist[i]) {
                dist[i] = dist[j] + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < size; i++) {
        ans = std::max(ans, dist[i]);
    }

    return ans;
}

std::vector<int> SubseqRecovery(std::vector<int> &dist, int max) {
    std::vector<int> seq(max, -1);

    for (int i = dist.size() - 1, j = max; i >= 0; i--) {
        if (dist[i] == j) {
            seq[--j] = i;
        }
    }

    return seq;
}

std::vector<int> SunseqFromIndex(std::vector<int> &arr, std::vector<int> &seqInd) {
    std::vector<int> result(seqInd.size());
    for (int i = 0; i < seqInd.size(); i++) {
        result[i] = arr[seqInd[i]];
    }

    return result;
}
