//
// Created by Chengwei Zhang on 7/5/20.
//

class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return 0;
        if (sz == 1) return nums[0];
        int* dp = new int[sz]{0};
        dp[0] = nums[0];
        dp[1] = nums[1];
        int maxNum = max(dp[0], dp[1]);
        for (int i = 2; i < sz; i ++) {
            for (int j = 0; j < i - 1; j ++) {
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
            maxNum = max(maxNum, dp[i]);
        }
        return maxNum;
    }
};