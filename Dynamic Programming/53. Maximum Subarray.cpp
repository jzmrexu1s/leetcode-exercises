//
// Created by Chengwei Zhang on 7/2/20.
//

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        int prevMax = nums[0];
        int allMax = nums[0];
        int i = 1;
        for (i; i < nums.size(); i ++) {
            prevMax = max(nums[i], nums[i] + prevMax);
            allMax = max(prevMax, allMax);
        }
        return allMax;
    }
};