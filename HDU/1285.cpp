//
// Created by Chengwei Zhang on 7/13/20.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;
vector<int> map[501];
int ind[501];

vector<int> topo(int n) {
    vector<int> seq;
    priority_queue<int, vector<int>, greater<int>> nodes;

    for (int i = 1; i <= n; i ++) {
        if (ind[i] == 0) nodes.push(i);
    }

    while (!nodes.empty()) {
        int node = nodes.top();
        nodes.pop();
        seq.push_back(node);
        for (int i = 0; i < map[node].size(); i ++) {
            int to = map[node][i];
            ind[to] --;
            if (ind[to] == 0) nodes.push(to);
        }
    }

    return seq;
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        memset(map, 0, sizeof(map));
        memset(ind, 0, sizeof(ind));
        if (n == 0 && m == 0) break;
        while (m > 0) {
            int win, lose;
            scanf("%d%d", &win, &lose);
            map[win].push_back(lose);
            ind[lose] ++;
            m --;
        }
        vector<int> r = topo(n);
        cout << r[0];
        for (int i = 1; i < r.size(); i ++) {
            cout <<  " " << r[i];
        }
        cout << endl;
    }
    return 0;
}