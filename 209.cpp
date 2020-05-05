//
// Created by Chengwei Zhang on 5/5/20.
//

/*

 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        int size = nums.size();

        if (size == 0) {
            return 0;
        }

        int l = -1;
        int r = 0;
        int minLen = size;
        int current = 0;
        bool found = false;

        for (; r < size; r ++) {

            current += nums[r];

            if (current >= s) {
                found = true;
                while (current >= s) {
                    l += 1;
                    current -= nums[l];
                }
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                }
            }

        }

        if (!found) return 0;
        return minLen;

    }
};