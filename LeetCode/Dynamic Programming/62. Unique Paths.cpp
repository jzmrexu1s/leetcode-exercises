//
// Created by Chengwei Zhang on 7/3/20.
//

class Solution {
public:
    int uniquePaths(int m, int n) {
        int **r = new int*[m];
        for (int i = 0; i < m; i ++) {
            r[i] = new int[n];
            for (int j = 0; j < n; j ++) {
                if (i == 0 && j == 0) r[i][j] = 1;
                else if (i == 0) r[i][j] = r[i][j - 1];
                else if (j == 0) r[i][j] = r[i - 1][j];
                else r[i][j] = r[i - 1][j] + r[i][j - 1];
            }
        }
        return r[m - 1][n - 1];
    }
};