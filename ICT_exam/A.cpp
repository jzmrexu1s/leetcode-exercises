//
// Created by Chengwei Zhang on 7/17/20.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <bitset>
#include <set>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) return 0;
        int* nums = new int[n];
        int maxNum = 0;
        int maxStrSize = 0;
        for (int i = 0; i < n; i ++) {
            scanf("%d", &nums[i]);
            maxNum = max(nums[i], maxNum);
            string str;
            bitset<10000000> t = n;
            str = t.to_string();
            maxStrSize = max((int)str.length(), maxStrSize);
        }
        int maxWith = 0;
        int cur;
        for (int i = maxStrSize - 1; i >= 0; i --) {
            maxWith <<= 1;
            cur = maxWith | 1;
            set<int> map;
            for (int j = 0; j < n; j ++) {
                int pre = nums[j] >> i;
                map.insert(pre);
            }
            for (int j = 0; j < n; j ++) {
                if (map.find(cur ^ map.find()) != map.end()) {
                    maxWith = cur;
                    break;
                }
            }
        }
        cout << maxWith << endl;
    }
    return 0;
}