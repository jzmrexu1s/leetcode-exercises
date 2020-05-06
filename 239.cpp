//
// Created by Chengwei Zhang on 5/7/20.
//

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        if (k == 1) return nums;
        int i = -1;
        int j = 0;
        int mx = 0;
        vector<int> maxs;

        for (; j < k; j ++) {
            if (nums[j] > nums[mx]) mx = j;
        }
        maxs.push_back(nums[mx]);

        for(j; j < size; j ++) {

            i ++;

            if (i == mx) {
                // 重新查找
                mx = i + 1;
                for (int t = i + 1; t <= j; t ++) {
                    if (nums[t] > nums[mx]) mx = t;
                }
            }
            else if (nums[j] > nums[mx]) {
                mx = j;
            }
            maxs.push_back(nums[mx]);
        }

        return maxs;

    }
};