//
// Created by Chengwei Zhang on 5/13/20.
//

// 第17行：数组排序

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int count[26];
        int time = 0;
        for (int i = 0; i < 26; i ++) {
            count[i] = 0;
        }
        for (int i = 0; i < tasks.size(); i ++) {
            int t = tasks[i] - 'A';
            count[t] += 1;
        }
        sort(count, count + 26);
        while (1) {
            int steps = n + 1;
            int p = 25;
            while (steps > 0 && count[p] > 0) {
                count[p] -= 1;
                time += 1;
                steps -= 1;
                p -= 1;
            }
            sort(count, count + 26);
            if (count[25] == 0) return time;
            time += steps;
        }
    }
};