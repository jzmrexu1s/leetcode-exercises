//
// Created by Chengwei Zhang on 5/6/20.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int bSearch(int sums[], int s, int left, int right) {
        int mid = -1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (sums[mid] == s) return mid;
            else if (sums[mid] < s) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return sums[mid] > s ? mid : -1;
    };

    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        int sums[size];

        int l = 0;
        int minLen = INT_MAX;

        sums[0] = nums[0];
        for (int i = 1; i < size; i ++) {
            sums[i] = sums[i - 1] + nums[i];
        }

        for (; l < size; l ++) {
            int s2 = s - nums[l];
            int result = bSearch(sums, s2 + sums[l], 0, size - 1);
            if (result >= 0) minLen = min(minLen, result - l + 1);
        }

        return minLen == INT_MAX ? 0 : minLen;

    };
};

int main() {
    Solution solution;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int r = solution.minSubArrayLen(7, nums);
    cout << "result: " << r << endl;
}