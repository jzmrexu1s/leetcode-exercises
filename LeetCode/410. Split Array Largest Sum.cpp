//
// Created by Chengwei Zhang on 9/2/20.
//

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int numsLen = nums.size();
        int** dp = new int*[numsLen];
        int* acc = new int[numsLen];

        acc[0] = nums[0];
        for (int i = 1; i < numsLen; i ++) {
            acc[i] = acc[i - 1] + nums[i];
        }

        for (int i = 0; i < numsLen; i ++) {
            dp[i] = new int[numsLen];
            dp[i][0] = 0;
            for (int j = 0; j <= i; j ++) {
                dp[i][0] += nums[j];
            }

            for (int j = 1; j < min(i + 1, m); j ++) {
                dp[i][j] = INT_MAX;
                for (int k = 0; k < i; k ++) {
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], acc[i] - acc[k]));
                }
            }
        }
        return dp[numsLen - 1][m - 1];
    }
};