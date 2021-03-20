#include <iostream>
#include <vector>
#include <ios>
#include <limits>
#include <algorithm>

int LNSBottomUp(std::vector<int> &arr, std::vector<int> &dist);
std::vector<int> LNSBottomUpImpr(std::vector<int> &arr);
std::vector<int> SubseqRecovery(std::vector<int> &dist, int max);
std::vector<int> SubseqFromIndex(std::vector<int> &arr, std::vector<int> &seqInd);
int lowerBound(std::vector<int> &arr, int left, int right, int k);
int lowerOrEqBound(std::vector<int> &arr, int left, int right, int k);

int main() {
    std::ios_base::sync_with_stdio(false);
    int count;
    std::cin >> count;
    std::vector<int> arr(count);
    std::vector<int> dist(count);
    for (int i = 0; i < count; i++) {
        std::cin >> arr[i];
    }

    int max = LNSBottomUp(arr, dist);
    std::vector<int> seq = SubseqRecovery(dist, max);

    std::cout << max << "\n";
    for (int i = 0; i < seq.size(); i++) {
        std::cout << seq[i] + 1 << " ";
    }
    std::cout << "\n";

    std::vector<int> res = LNSBottomUpImpr(arr);

    std::cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] + 1 << " ";
    }

    return 0;
}

int LNSBottomUp(std::vector<int> &arr, std::vector<int> &dist) {
    size_t size = arr.size();
    for (int i = 0; i < size; i++) {
        dist[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] >= arr[i] && (dist[j] + 1) > dist[i]) {
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

std::vector<int> LNSBottomUpImpr(std::vector<int> &arr) {
    std::vector<int> prev(arr.size(), -1);
    std::vector<int> dist(arr.size() + 1);
    dist[0] = INT32_MAX;
    for (int i = 1; i < dist.size(); i++) {
        dist[i] = INT32_MIN;
    }
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        //int j = static_cast<int>(std::lower_bound(dist.begin(), dist.end(), arr[i]) - dist.begin());
        int j = lowerOrEqBound(dist, 0, dist.size() - 1, arr[i]);
        if (arr[i] > dist[j] && arr[i] <= dist[j - 1]) {
            dist[j] = arr[i];
            prev[i] = j;
        }
        if (j > ans) {
            ans = j;
        }
    }

    std::vector<int> result(ans);
    int i = arr.size() - 1;
    while (ans > 0) {
        if (prev[i] == ans) {
            result[--ans] = i;
        }
        i--;
    }

    return result;
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

std::vector<int> SubseqFromIndex(std::vector<int> &arr, std::vector<int> &seqInd) {

}

int lowerBound(std::vector<int> &arr, int left, int right, int k) {
    int result = -1;
    while (left < right) {
        int mid = left + ((right - left) / 2);
        if (arr[mid] > k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    result = right;
    return result;
}

int lowerOrEqBound(std::vector<int> &arr, int left, int right, int k) {
    int result = -1;
    while (left < right) {
        int mid = left + ((right - left) / 2);
        if (arr[mid] >= k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    result = right;
    return result;
}
