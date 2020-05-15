//
// Created by Chengwei Zhang on 5/13/20.
//

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int count[26];
        int haveCount = 0;
        int time = 0;
        for (int i = 0; i < 26; i ++) {
            count[i] = 0;
        }
        for (int i = 0; i < tasks.size(); i ++) {
            int t = tasks[i] - 65;
            if (count[t] == 0) haveCount += 1;
            count[t] += 1;
        }
        while (1) {
            sort(count, count + 26);
            int steps = n + 1;
            int p = 25;
            while (steps > 0 && count[p] > 0) {
                count[p] -= 1;
                if (count[p] == 0) haveCount -=1;
                time += 1;
                steps -= 1;
                p -= 1;
                if (haveCount == 0) return time;
            }
            time += steps;
        }
    }
};