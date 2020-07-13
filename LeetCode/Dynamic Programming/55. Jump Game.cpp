//
// Created by Chengwei Zhang on 7/3/20.
//

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = 0;
        int mx = nums.size();
        for (int i = 0; i < mx; i ++) {
            if (far >= i) {
                far = max(far, i + nums[i]);
                if (far >= mx - 1) return true;
            }
        }
        return false;
    }
};