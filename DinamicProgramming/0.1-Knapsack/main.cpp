#include <iostream>
#include <vector>
#include <ios>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);

    int knapsackCap = 0; // colCount
    int goldBarsCount = 0; // rowCount

    int &colCount = knapsackCap;
    int &rowCount = goldBarsCount;

    std::cin >> colCount >> rowCount;
    int *gbWeights = new int[rowCount];
    for (int i = 0; i < rowCount; i++) {
        std::cin >> gbWeights[i];
    }

    int **arr = new int *[rowCount + 1];
    for (int i = 0; i <= rowCount; i++) {
        arr[i] = new int[colCount + 1];
    }

    // Так
    /*for (int i = 0; i <= rowCount; i++) {
        for (int j = 0; j <= colCount; j++) {
            arr[i][j] = 0;
        }
    }*/
    // Или так
    for (int i = 0; i <= colCount; i++) {
        arr[0][i] = 0;
    }
    for (int i = 0; i <= rowCount; i++) {
        arr[i][0] = 0;
    }

    for (int i = 1; i <= rowCount; i++) {
        for (int j = 1; j <= colCount; j++) {
            if (j >= gbWeights[i-1]) {
                arr[i][j] = std::max(arr[i - 1][j], arr[i - 1][j - gbWeights[i - 1]] + gbWeights[i - 1]);
            } else {
                arr[i][j] = arr[i - 1][j];
            }
        }
    }

    std::cout << arr[rowCount][colCount];

    return 0;
}
