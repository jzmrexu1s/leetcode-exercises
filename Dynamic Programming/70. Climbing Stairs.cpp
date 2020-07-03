//
// Created by Chengwei Zhang on 7/3/20.
//

class Solution {
public:
    int climbStairs(int n) {
        int* counts = new int[n + 1];
        counts[0] = 1;
        counts[1] = 1;
        for (int i = 2; i < n + 1; i ++) {
            counts[i] = counts[i - 1] + counts[i - 2];
        }
        return counts[n];
    }
};