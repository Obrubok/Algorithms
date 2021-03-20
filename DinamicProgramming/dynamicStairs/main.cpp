#include <iostream>
#include <ios>
#include <vector>

long maxSum(std::vector<int>& values, int stepsCount);

int main() {
    std::ios_base::sync_with_stdio(false);

    int countOfSteps;

    std::cin >> countOfSteps;
    std::vector<int> stepsValues(countOfSteps + 1);
    stepsValues[0] = 0;
    for (int i = 1; i <= countOfSteps; i++) {
        std::cin >> stepsValues[i];
    }

    long result = maxSum(stepsValues, countOfSteps);
    std::cout << result;

    return 0;
}

long maxSum(std::vector<int> &values, int stepsCount) {
    if (stepsCount == 0) return 0;
    if (stepsCount == 1) return values[1];

    std::vector<long> sums(stepsCount + 1);
    sums[0] = 0;
    sums[1] = values[1];

    for (int i = 2; i <= stepsCount; i++) {
        sums[i] = std::max(sums[i - 1], sums[i - 2]) + values[i];
    }

    return sums[stepsCount];
}
