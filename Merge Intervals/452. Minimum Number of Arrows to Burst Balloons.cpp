//
// Created by Chengwei Zhang on 5/13/20.
//
// 第10行：vector自定义排序

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), [](const vector<int> &o1, const vector<int> &o2) {return (o1[1] < o2[1]);});
        int minArrows = 1;
        int right = points[0][1];
        for (int i = 1; i < points.size(); i ++) {
            if (points[i][0] > right) {
                minArrows ++;
                right = points[i][1];
            }
        }
        return minArrows;
    }
};