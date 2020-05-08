//
// Created by Chengwei Zhang on 5/8/20.
//

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int l = 0;
        int r = 0;
        int prod = 1;
        int sum = 0;
        while (r < nums.size()) {
            prod *= nums[r];
            while (l <= r && prod >= k) {
                prod /= nums[l];
                l ++;
            }
            sum += r - l + 1;
            r ++;
        }
        return sum;
    }
};