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

struct Line{
    int a;
    int b;
    int c;
};

struct Point{
    int x;
    int y;
};

//Point getCross(Line x, Line y) {
//    Point cross;
//    int d = x.a * y.b - y.a * x.b;
//    int cx = (x.b * y.c - y.b * x.c) / d;
//    int cy = (y.a * x.c - x.a * y.c) / d;
//    cross.x = cx;
//    cross.y = cy;
//    return cross;
//}

bool isLeft(Point p, Line l) {
    if (l.b == 0) return p.x < (0 - l.c) / l.a;
    int newy = (0 - l.c - l.a * p.x) / l.b;
    return newy > p.y;
}

int main() {
    int n;
    scanf("%d", &n);
    Line* lines = new Line[n];
    for (int i = 0; i < n; i ++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        Line t{a, b, c};
        lines[i] = t;
    }
    int x, y;
    scanf("%d%d", &x, &y);
    Point start{x, y};
    scanf("%d%d", &x, &y);
    Point end{x, y};

    int count = 0;
    for (int i = 0; i < n; i ++) {
        if (isLeft(start, lines[i]) != isLeft(end, lines[i])) count ++;
    }
    cout << count << endl;

//    vector<Point>* crosses = new vector<Point>[n];
//    for (int i = 0; i < n; i ++) {
//        for (int j = 0; j < n; j ++) {
//            if (i != j) crosses[i].push_back();
//        }
//    }


    return 0;
}