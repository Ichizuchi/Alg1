#include <stdio.h>

#define N 10 // Set N to 10 as per your example

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int matrix[N][N] = {
        {2, 79, 5, 75, 7, 98, 53, 92, 72, 39},
        {48, 31, 23, 15, 98, 87, 3, 3, 47, 26},
        {6, 12, 59, 2, 33, 66, 42, 69, 75, 1},
        {48, 88, 45, 64, 17, 43, 83, 11, 1, 71},
        {66, 1, 27, 14, 2, 8, 41, 11, 15, 28},
        {35, 1, 64, 73, 26, 34, 10, 12, 31, 91},
        {8, 37, 48, 2, 50, 41, 65, 33, 86, 4},
        {36, 64, 5, 99, 94, 70, 33, 50, 98, 16},
        {28, 1, 69, 16, 25, 63, 19, 21, 84, 56},
        {79, 39, 15, 9, 77, 6, 12, 72, 32, 18}
    };

    int max_dp[N][N];
    int min_dp[N][N];

    max_dp[0][0] = min_dp[0][0] = matrix[0][0];

    for (int i = 1; i < N; i++) {
        max_dp[0][i] = max_dp[0][i - 1] + matrix[0][i];
        min_dp[0][i] = min_dp[0][i - 1] + matrix[0][i];
        max_dp[i][0] = max_dp[i - 1][0] + matrix[i][0];
        min_dp[i][0] = min_dp[i - 1][0] + matrix[i][0];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            max_dp[i][j] = max(max_dp[i - 1][j], max_dp[i][j - 1]) + matrix[i][j];
            min_dp[i][j] = min(min_dp[i - 1][j], min_dp[i][j - 1]) + matrix[i][j];
        }
    }
    printf("%d %d\n", max_dp[N - 1][N - 1], min_dp[N - 1][N - 1]);

    return 0;
}