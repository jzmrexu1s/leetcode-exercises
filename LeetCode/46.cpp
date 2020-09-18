//
// Created by Chengwei Zhang on 9/18/20.
//

class Solution {
private:
    vector<vector<int>> res;
    void rec(vector<int>& nums, int cur) {
        if (nums.size() == cur + 1) {
            res.push_back(nums);
            return;
        }
        for (int i = cur; i < nums.size(); i ++) {
            swap(nums[i], nums[cur]);
            rec(nums, cur + 1);
            swap(nums[i], nums[cur]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        rec(nums, 0);
        return res;
    }
};