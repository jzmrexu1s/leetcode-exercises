//
// Created by Chengwei Zhang on 7/16/20.
//

#include <iostream>
#include <cstdio>
#include <climits>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int* nums = new int[n];
    for (int i = 0; i < n; i ++) {
        int t;
        scanf("%d", &t);
        nums[i] = t;
    }
    int maxLen = 2;
    sort(nums, nums + n);
    unordered_map<int, int>* dp = new unordered_map<int, int>[n];
    dp[1][nums[1] - nums[0]] = 2;
    for (int i = 2; i < n; i ++) {
        for (int j = 0; j < i; j ++) {
            int dis = nums[i] - nums[j];
            if (dp[j].find(dis) != dp[j].end()) {
                dp[i][dis] = dp[j][dis] + 1;
            } else {
                dp[i][dis] = 2;
            }
            maxLen = max(maxLen, dp[i][dis]);
        }
    }
    cout << maxLen;
    return 0;
}