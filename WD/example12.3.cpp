//
// Created by Chengwei Zhang on 7/17/20.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int makeDp(int* lineSum, int n) {
    int* dp = new int[n];
    dp[0] = lineSum[0];
    int maxSum = dp[0];
    for (int i = 1; i < n; i ++) {
        dp[i] = max(dp[i - 1] + lineSum[i], lineSum[i]);
        maxSum = max(maxSum, dp[i]);
    }
    return maxSum;
}

int recLines(int** sums, int n) {
    int maxSum = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            int *lineSum = new int[n];
            for (int k = 0; k < n; k++) {
                if (i == 0) lineSum[k] = sums[i][k];
                else lineSum[k] = sums[j][k] - sums[i - 1][k];
            }
            maxSum = max(maxSum, makeDp(lineSum, n));
        }
    }
    return maxSum;
}

int** makeSums(int** matrix, int n) {
    int **sums = new int *[n];
    for (int i = 0; i < n; i ++) {
        sums[i] = new int[n];
        for (int j = 0; j < n; j ++) {
            if (i == 0) sums[i][j] = matrix[i][j];
            else sums[i][j] = sums[i - 1][j] + matrix[i][j];
        }
    }
    return sums;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int **matrix = new int *[n];
        for (int i = 0; i < n; i ++) {
            matrix[i] = new int[n];
            for (int j = 0; j < n; j ++) {
                scanf("%d", &matrix[i][j]);
            }
        }
        int** sums = makeSums(matrix, n);
        cout << recLines(sums, n) << endl;
    }
}