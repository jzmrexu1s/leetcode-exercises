//
// Created by Chengwei Zhang on 10/24/20.
//

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct Point {
    float x;
    float y;
};

bool checkIntersect(Point a1, Point a2, Point b1, Point b2) {
    return min(a1.x, a2.x) <= max(b1.x, b2.x) && min(b1.x, b2.x) <= max(a1.x, a2.x) &&
           min(a1.y, a2.y) <= max(b1.y, b2.y) && min(b1.y, b2.y) <= max(a1.y, a2.y);
}

float getDirection(Point a, Point b, Point c) {
    return (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
}

vector<int> getBorder(Point pts[], int n) {
    vector<int> q;
    if (n == 1) {
        q.push_back(0);
        return q;
    }
    if (n == 2) {
        q.push_back(0);
        q.push_back(1);
        return q;
    }
    int first = 0;
    for (int i = 1; i < n; i ++) {
        if (pts[i].x < pts[first].x || (pts[i].x == pts[first].x && pts[i].y < pts[first].y)) first = i;
    }
    int cur = first;
    int next;
    q.push_back(cur);
    do {
//        cout << cur << endl;
        next = (cur + 1) % n;
        for (int i = 0; i < n; i ++) {
            if (i != cur && getDirection(pts[cur], pts[i], pts[next]) < 0) {
                next = i;
            }
        }
        cur = next;
        q.push_back(cur);

    } while (cur != first);
    return q;
}


int main() {
    int T;
    scanf("%d", &T);
    for(int times = 0; times < T; times ++) {
        Point ptsP[100000];
        Point ptsN[100000];
        int N;
        scanf("%d", &N);
        int j = 0;
        int k = 0;
        for(int i = 0; i < N; i ++) {
            float x;
            float y;
            int label;
            scanf("%f%f%d", &x, &y, &label);
            Point p{x, y};
            if (label == 1) {
                ptsP[j] = p;
                j ++;
            }
            else {
                ptsN[k] = p;
                k ++;
            }
        }
//        cout << j << " " << k << endl;
        vector<int> edgeP = getBorder(ptsP, j);
        vector<int> edgeN = getBorder(ptsN, k);
//        cout << endl;
//        for (int i = 0; i < edgeP.size(); i ++) {
//            cout << edgeP[i] << " ";
//        }
//        cout << endl;
//        for (int i = 0; i < edgeN.size(); i ++) {
//            cout << edgeN[i] << " ";
//        }
//        cout << endl;

        bool r = true;
        for (int p = 0; p < edgeP.size() - 1; p ++) {
            if (!r) break;
            for (int q = 0; q < edgeN.size() - 1; q ++) {
                if (checkIntersect(ptsP[edgeP[p]], ptsP[edgeP[p + 1]], ptsN[edgeN[q]], ptsN[edgeN[q + 1]])) {
                    r = false;
                    break;
                }
            }
        }
        if (r) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}