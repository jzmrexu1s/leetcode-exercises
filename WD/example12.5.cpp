//
// Created by Chengwei Zhang on 10/9/20.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int nums[1000];
int dp[1000];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i ++) scanf("%d", &nums[i]);
        dp[0] = 1;
        int maxCount = 1;
        for (int i = 1; i < n; i ++) {
            dp[i] = 0;
            for (int j = 0; j < i; j ++) {
                dp[i] = nums[i] <= nums[j] ? max(dp[i], dp[j] + 1) : max(dp[i], 1);
            }
            maxCount = max(maxCount, dp[i]);
        }
        printf("%d\n", maxCount);
    }
    return 0;
}