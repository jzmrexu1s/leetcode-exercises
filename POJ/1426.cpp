//
// Created by Chengwei Zhang on 10/5/20.
//

#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        queue<long long> q;
        q.push(1);
        while (!q.empty()) {
            long long t = q.front();
            if (t % n == 0) {
                printf("%lld\n", t);
                break;
            }
            q.pop();
            q.push(t * 10);
            q.push(t * 10 + 1);
        }
    }
    return 0;
}