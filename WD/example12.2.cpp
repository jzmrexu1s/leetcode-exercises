//
// Created by Chengwei Zhang on 7/16/20.
//

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int m;
    while (scanf("%d", &m) != EOF) {
        int* nums = new int[m];
        for (int i = 0; i < m; i ++) {
            int t;
            scanf("%d", &t);
            nums[i] = t;
        }
        int* dp = new int[m];
        dp[0] = nums[0];
        int maxVal = dp[0];
        for (int i = 1; i < m; i ++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            maxVal = max(maxVal, dp[i]);
        }
        cout << maxVal << endl;
    }
    return 0;
}