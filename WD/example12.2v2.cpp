//
// Created by Chengwei Zhang on 10/9/20.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

long long nums[1000000];
long long dp[1000000];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i ++) scanf("%lld", &nums[i]);
        long long maxVal = 0;
        dp[0] = nums[0];
        for (int i = 1; i < n; i ++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            maxVal = max(maxVal, dp[i]);
        }
        printf("%lld\n", maxVal);
    }
    return 0;
}