//
// Created by Chengwei Zhang on 5/11/20.
//

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int right0 = 0;
        int left2 = size - 1;
        int p = 0;
        while (p <= left2) {
            if (nums[p] == 0) {
                swap(nums[right0], nums[p]);
                right0 ++;
                p ++;
            }
            else if (nums[p] == 2) {
                swap(nums[left2], nums[p]);
                left2 --;
            }
            else {
                p ++;
            }
        }

    }
};