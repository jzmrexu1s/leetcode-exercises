//
// Created by Chengwei Zhang on 7/4/20.
//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        if (sz == 0 || sz == 1) return 0;
        int* maxs = new int[sz];
        maxs[0] = 0;
        int lowest = 0;
        for (int i = 1; i < sz; i ++) {
            if (prices[i] < prices[lowest]) lowest = i;
            maxs[i] = max(maxs[i - 1], prices[i] - prices[lowest]);
        }
        return maxs[sz - 1];
    }
};