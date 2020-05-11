//
// Created by Chengwei Zhang on 5/11/20.
//

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        if (intervals.empty()) return merged;
        sort(intervals.begin(), intervals.end());
        merged.push_back(intervals[0]);
        int i = 1;
        while (i < intervals.size()) {
            if (intervals[i][0] > merged.back()[1]) merged.push_back(intervals[i]);
            else merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            i ++;
        }
        return merged;
    }
};