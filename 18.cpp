//
// Created by Chengwei Zhang on 3/12/20.
//

/*
 * 思路：
 * 每一项a[i]都认为是能组成和为0的一个数字；
 * 先排序，然后使用双指针找到剩下两个合为-a[i]的数字。
 * vector排序：sort(vector.begin(), vector.end())
 * vector交换其中两项：swap()
 * 判断条件有序：判断 A && B，首先会判断A是否满足，如果不满足则不判断B。这样可以避免数组越界（61行）。
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    static void quickSort(vector<int>& arr, int left, int right) {
        if (left >= right) {
            return;
        }
        int i = left;
        int j = right;
        int p = arr[left];
        while (i != j) {
            while (arr[j] >= p && i < j) {
                j --;
            }
            while (arr[i] <= p && i < j) {
                i ++;
            }
            if (i < j) {
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[left], arr[i]);
        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);
    }

public:
    static vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        // quickSort(nums, 0, nums.size() - 1);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] > 0) return result;
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    vector<int> t = {nums[i], nums[l], nums[r]};
                    result.push_back(t);

                    while (l < r && nums[l] == nums[l + 1]) {
                        l ++;
                    }
                    while (l < r && nums[r] == nums[r - 1]) {
                        r --;
                    }
                    if (l < r) {
                        l ++;
                        r --;
                    }
                }
                else if (sum < 0) {
                    l ++;
                }
                else {
                    r --;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 0, 0};
    vector<vector<int>> result = Solution::threeSum(nums);
    for (const vector<int> &j : result) {
        for (const int &k: j) {
            cout << k << ", ";
        }
        cout << endl;
    }
}