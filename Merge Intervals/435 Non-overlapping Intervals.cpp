//
// Created by Chengwei Zhang on 5/13/20.
//

class Solution {
public:
    vector<int> getMaxCount(int len, vector<vector<int>>& intervals) {
        if (len == 1) {
            vector<int> t = {1};
            return t;
        }
        vector<int> maxCount = getMaxCount(len - 1, intervals);
        int maxOne = 0;
        for (int i = 0; i < maxCount.size(); i ++) {
            if (intervals[len - 1][0] >= intervals[i][1]) maxOne = max(maxCount[i], maxOne);
        }
        maxCount.push_back(maxOne + 1);
        return maxCount;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end());
        vector<int> maxCount = getMaxCount(intervals.size(), intervals);
        int mx = 0;
        for (int i = 0; i < maxCount.size(); i ++) {
            mx = max(mx, maxCount[i]);
        }
        return intervals.size() - mx;
    }
};