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
    int n;
    while (scanf("%d", &n) != 0) {
        if (n == 0) return 0;
        int* a = new int[n];
        int* b = new int[n];
        for (int i = 0; i < n; i ++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i ++) {
            scanf("%d", &b[i]);
        }
        sort(a, a + n);
        sort(b, b + n);
        int j = 1;
        for (int i = 0; i < n / 2; i ++) {
            int t = b[i];
            b[i] = b[n - j];
            b[n - j] = t;
            j ++;
        }
        int sum = 0;
        for (int i = 0; i < n; i ++) {
            sum += a[i] * b[i];
        }
        cout << sum << endl;
    }
    return 0;
}