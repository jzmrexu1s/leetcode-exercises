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

int main() {
    int k;
    while (scanf("%d", &k) != EOF) {
        int* nums = new int[k];
        for (int i = 0; i < k; i ++) {
            scanf("%d", &nums[i]);
        }
        int* dp = new int[k];
        dp[0] = 1;
        int maxLen = dp[0];
        for (int i = 1; i < k; i ++) {
            dp[i] = 1;
            for (int j = 0; j < i; j ++) {
                if (nums[i] <= nums[j]) dp[i] = std::max(dp[i], dp[j] + 1);
            }
            maxLen = std::max(maxLen, dp[i]);
        }
        std::cout << maxLen << std::endl;
    };
}