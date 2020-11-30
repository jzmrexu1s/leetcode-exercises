//
// Created by Chengwei Zhang on 7/31/20.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
#include <limits>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;
double pi = 3.1415926535;

struct Point{
    int x;
    int y;
};

double getDist(Point p1, Point p2) {
    return pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2);
}

int main() {
    int n;
    scanf("%d", &n);
    Point* points = new Point[n];
//    double** dists = new double*[n];
    for (int i = 0; i < n; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        Point p = {x, y};
        points[i] = p;
    }
    double allMin = INT_MAX;
    for (int i = 0; i < n; i ++) {
//        dists[i] = new double[n];
//        dists[i][0] = 0;
        double tmpMax = 0;
        for (int j = 1; j < n; j ++) {
            tmpMax = max(tmpMax, getDist(points[i], points[j]));
        }
        allMin = min(allMin, tmpMax);
    }
    printf("%.4f", allMin * pi);
    return 0;
}
