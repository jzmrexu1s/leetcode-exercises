//
// Created by Chengwei Zhang on 10/10/20.
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

struct node {
    int val;
    vector<int> children;
};

struct guest {
    string name;
    int port;
    int priority;
};

const int MAXN = 300;
vector<int> sons[MAXN];
int fathers[MAXN];
bool visited[MAXN];
guest guests[1000];
bool sentG[MAXN];

int minLen;
vector<int> minPath;

bool comp(const guest &a, const guest &b) {
    return a.priority < b.priority;
}

void getMinPath(int from, int to, int depth, vector<int> path) {
    if (from == to) {
        minLen = min(minLen, depth);
        path.push_back(to);
        minPath = path;
    }
    for (int i = 0; i < 100; i ++) {
        if (!visited[sons[from][i]]) {
            visited[sons[from][i]] = true;
            path.push_back(sons[from][i]);
            getMinPath(sons[from][i], to, depth + 1, path);
            path.pop_back();
            visited[sons[from][i]] = false;
        }
    }
    if (!visited[fathers[from]]) {
        visited[fathers[from]] = true;
        path.push_back(visited[fathers[from]]);
        getMinPath(fathers[from], to, depth + 1, path);
        path.pop_back();
        visited[fathers[from]] = false;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i ++) {
        int child, father;
        scanf("%d%d", &child, &father);
        sons[father].push_back(child);
        fathers[child] = father;
    }

    int m;
    cin.ignore();
    scanf("%d", &m);
    for (int i = 0; i < m; i ++) {
        guest g;
        cin >> g.name;
        cin.ignore();
        scanf("%d%d", &g.port, &g.priority);
    }
    sort(guests, guests + m, comp);
    int sent = 0;
    int cur = 100;
    while (sent < m) {
        int next;
        for (int i = 0; i < m; i ++) {
            if (!sentG[i]) {
                next = i;
                break;
            }
        }
        vector<int> path;
        getMinPath(cur, next, 0, path);
        int j = 0;
        while (cur != next) {
            cur = path[j];
            for (int k = 0; k < m; k ++) {
                if (guests[k].port == cur) {
                    sentG[k] = true;
                    cout << guests[k].name << " " << guests[k].port << endl;
                }
            }
            j ++;
        }
    }
}