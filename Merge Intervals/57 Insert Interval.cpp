//
// Created by Chengwei Zhang on 5/13/20.
//

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        int l = newInterval[0];
        int r = newInterval[1];
        int lPos = -2;
        int rPos = -2;
        bool lOut = true;
        bool rOut = true;
        bool lEnd = false;
        bool rEnd = false;
        int i = 0;
        while (i < intervals.size()) {
            if (l < intervals[i][0]) {
                lPos = i;
                lOut = true;
                break;
            }
            if (l <= intervals[i][1] && l >= intervals[i][0]) {
                lPos = i;
                lOut = false;
                break;
            }
            i ++;
        }
        if (lPos == -2) {
            lPos = intervals.size() - 1;
            lEnd = true;
        }
        while (i < intervals.size()) {
            if (r < intervals[i][0]) {
                rPos = i - 1;
                rOut = true;
                break;
            }
            if (r <= intervals[i][1] && r >= intervals[i][0]) {
                rPos = i;
                rOut = false;
                break;
            }
            i ++;
        }
        if (rPos == -2) {
            rPos = intervals.size() - 1;
            rEnd = true;
        }
        int lVal = lOut ? l : intervals[lPos][0];
        int rVal = rOut ? r : intervals[rPos][1];
        // cout << lPos << "," << rPos << endl;
        vector<int> v = {lVal, rVal};
        if (intervals.empty()) intervals.push_back(v);
        else if (lEnd && rEnd) intervals.push_back(v);
        else if (lOut && rOut && lPos == 0 && rPos == -1) intervals.insert(intervals.begin(), v);
        else {
            intervals.erase(intervals.begin() + lPos, intervals.begin() + rPos + 1);
            intervals.insert(intervals.begin() + lPos, v);
        }
        return intervals;
    }
};