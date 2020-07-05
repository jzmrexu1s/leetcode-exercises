//
// Created by Chengwei Zhang on 7/4/20.
//

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return 0;
        int* dpMin = new int[sz];
        int* dpMax = new int[sz];
        dpMin[0] = nums[0];
        dpMax[0] = nums[0];
        int maxVal = nums[0];
        for (int i = 1; i < sz; i ++) {
            dpMin[i] = min(nums[i], min(dpMin[i - 1] * nums[i], dpMax[i - 1] * nums[i]));
            dpMax[i] = max(nums[i], max(dpMin[i - 1] * nums[i], dpMax[i - 1] * nums[i]));
            maxVal = max(dpMax[i], maxVal);
        }
        return maxVal;
    }
};