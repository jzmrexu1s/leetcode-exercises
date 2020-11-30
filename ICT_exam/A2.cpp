//
// Created by Chengwei Zhang on 7/17/20.
//

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

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) return 0;
        int* nums = new int[n];
        int maxNum = 0;
        for (int i = 0; i < n; i ++) {
            scanf("%d", &nums[i]);
        }
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i != j) maxNum = max(maxNum, nums[i] & nums[j]);
            }
        }
        cout << maxNum << endl;
    }
    return 0;
}