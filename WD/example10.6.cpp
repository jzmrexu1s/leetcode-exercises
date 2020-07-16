//
// Created by Chengwei Zhang on 7/16/20.
//

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        priority_queue<int, vector<int>, greater<int>> q;
        while (n > 0) {
            int t;
            scanf("%d", &t);
            q.push(t);
            n --;
        }
        int res = 0;
        while (q.size() > 1) {
            int t1 = q.top();
            q.pop();
            int t2 = q.top();
            q.pop();
            res += t1 + t2;
            q.push(t1 + t2);
        }
        cout << res << endl;
    }
    return 0;
}