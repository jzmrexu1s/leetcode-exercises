//
// Created by Chengwei Zhang on 9/18/20.
//

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int sz = a.size();
        vector<int> r(sz);
        if (sz == 0) return r;
        r[0] = 1;
        for (int i = 1; i < sz; i ++) r[i] = r[i - 1] * a[i - 1];
        int tmp = 1;
        for (int i = sz - 1; i >= 0; i --) {
            r[i] = r[i] * tmp;
            tmp = tmp * a[i];
        }
        return r;
    }
};