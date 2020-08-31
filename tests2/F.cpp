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

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        int a1, a2, a3, b1, b2, b3;
        scanf("%d%d%d%d%d%d", &a1, &a2, &a3, &b1, &b2, &b3);
        int a4 = 0;
        int b4 = 0;
        while (a1 > 0 && b3 > 0) {
            a1 --;
            b3 --;
            b4 ++;
        }
        while (a2 > 0 && b2 > 0) {
            a2 --;
            b2 --;
            b4 ++;
        }
        t --;
    }
    return 0;
}