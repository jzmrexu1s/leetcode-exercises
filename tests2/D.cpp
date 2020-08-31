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

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        int n;
        float v;
        scanf("%d%f", &n, &v);
        float* nums = new float[n];
        for (int i = 0; i < n; i ++) {
            scanf("%f", &nums[i]);
        }
        sort(nums, nums + n);
        int idn = 0;
        int last = nums[0];
        while (last == nums[idn]) {
            idn ++;
        }
        while (true) {
            if (idn == n) {
                cout << ceil(nums[0] + v / idn) << endl;
                break;
            }
            if (v >= (nums[idn] - nums[0]) * float(idn)) {
                v = v - (nums[idn] - nums[0]) * float(idn);
                for (int i = 0; i < idn; i ++) {
                    nums[i] = nums[idn];
                }
                idn ++;
            }
            else {
                cout << ceil(nums[0] + v / idn) << endl;
                break;
            }
        }
        t --;
    }
    return 0;
}
