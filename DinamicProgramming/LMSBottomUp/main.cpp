#include <iostream>
#include <vector>

long LMSBottomUp(std::vector<long> &arr, std::vector<long> &dist);
std::vector<long> SubseqRecovery(std::vector<long> &dist, long max);
std::vector<long> SubseqFromIndex(std::vector<long> &arr, std::vector<long> &seqInd);

int main() {
    long count;
    std::cin >> count;
    std::vector<long> arr(count);
    std::vector<long> dist(count, -1);
    for (long i = 0; i < count; ++i) {
        std::cin >> arr[i];
    }

    long k = LMSBottomUp(arr, dist);
    std::cout << k;

    return 0;
}

long LMSBottomUp(std::vector<long> &arr, std::vector<long> &dist) {
    size_t size = arr.size();
    for (long i = 0; i < size; i++) {
        dist[i] = 1;
        for (long j = 0; j < i; j++) {
            if (arr[j] <= arr[i] && (dist[j] + 1) > dist[i] && (arr[i] % arr[j]) == 0) {
                dist[i] = dist[j] + 1;
            }
        }
    }
    long ans = 0;
    for (long i = 0; i < size; i++) {
        ans = std::max(ans, dist[i]);
    }

    return ans;
}

std::vector<long> SubseqRecovery(std::vector<long> &dist, long max) {
    std::vector<long> seq(max, -1);

    for (long i = dist.size() - 1, j = max; i >= 0; i--) {
        if (dist[i] == j) {
            seq[--j] = i;
        }
    }

    return seq;
}

std::vector<long> SunseqFromIndex(std::vector<long> &arr, std::vector<long> &seqInd) {
    std::vector<long> result(seqInd.size());
    for (long i = 0; i < seqInd.size(); i++) {
        result[i] = arr[seqInd[i]];
    }

    return result;
}