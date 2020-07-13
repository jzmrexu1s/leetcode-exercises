//
// Created by Chengwei Zhang on 7/5/20.
//

class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return 0;
        if (sz == 1) return nums[0];
        if (sz == 2) return max(nums[0], nums[1]);
        int* dp0 = new int[sz]{0};
        int* dp1 = new int[sz]{0};
        dp0[0] = nums[0];
        dp0[1] = nums[1];
        dp1[1] = nums[1];
        dp1[2] = nums[2];
        int maxNum = max(dp0[0], dp0[1]);
        for (int i = 2; i < sz - 1; i ++) {
            for (int j = 0; j < i - 1; j ++) {
                dp0[i] = max(dp0[i], dp0[j] + nums[i]);
                if (i != 2) dp1[i] = max(dp1[i], dp1[j] + nums[i]);
                maxNum = max(maxNum, dp0[i]);
            }
        }
        for (int j = 0; j < sz - 2; j ++) {
            dp0[sz - 1] = max(dp0[sz - 1], dp1[j] + nums[sz - 1]);
            maxNum = max(maxNum, dp0[sz - 1]);
        }
        return maxNum;
    }
};