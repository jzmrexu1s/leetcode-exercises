//
// Created by Chengwei Zhang on 7/31/20.
//

// 思路：先使用迪杰斯特拉算出图中每个点到其他点的距离，然后使用TSP算法即可（代码来不及写完）。

#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct Path{
    int to;
    int weight;
};

int* dij(int start, vector<Path>* map, int n) {
    int* minDists = new int[n];
    bool* visitedMap = new bool[n];
    int* prevs = new int[n];
    for (int i = 0; i < n; i ++) {
        minDists[i] = INT_MAX;
        visitedMap[i] = false;
    }
    for (int i = 0; i < map[0].size(); i ++) {
        int cur = map[0][i].to;
        minDists[cur] = map[0][i].weight;
    }
    int p = start;
    int visited = 1;
    /*
     * dij算法进行过程
     */
    while (visited < n) {
        for (int i = 0; i < map[p].size(); i ++) {
            int cur = map[p][i].to;
            minDists[cur] = min(minDists[i], minDists[p] + map[p][cur].weight);
        }
        int minTmp = INT_MAX;
        int sel = 0;
        for (int i = 0; i < n; i ++) {
            if (!visitedMap[i] && minDists[i] < minTmp) {
                sel = i;
                minTmp = minDists[i];
            }
        }
        visitedMap[sel] = true;
        prevs[sel] = p;
        p = sel;
        visited ++;
    }
    int* res = new int[n];
    /*
     * 获取最短距离
     */
    for (int i = 0; i < n; i ++) {
        res[i] = 0;
        int p = i;
        while (p != start) {
            res[i] += map[p][prevs[i]].weight;
            p = prevs[i];
        }
    }
    return res;
}

int main() {
    /*
     * 输入
     */
    int n, m;
    scanf("%d%d", &n, &m);
    vector<Path>* map = new vector<Path>[m];
    for (int i = 0; i < m; i ++) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        Path p = {y, w};
        map[x].push_back(p);
    }
    int p;
    scanf("%d", &p);
    int* tres = new int[p];
    for (int i = 0; i < p; i ++) {
        scanf("%d", &tres[i]);
    }
    /*
     * 计算各点间最短距离
     */
    int** minLengths = new int*[n];
    for (int i = 0; i < n; i ++) {
        minLengths[i] = dij(i, map, n);
    }
    /*
     * TSP
     */

    return 0;
}