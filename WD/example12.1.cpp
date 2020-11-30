//
// Created by Chengwei Zhang on 10/9/20.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int dp[91];
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < 91; i ++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int n;
    while (scanf("%d", &n) != EOF) printf("%d\n", dp[n - 1]);
    return 0;
}