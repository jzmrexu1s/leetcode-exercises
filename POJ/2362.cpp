//
// Created by Chengwei Zhang on 10/6/20.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <climits>
using namespace std;

const int MAXN = 20;
int n;
int m;
int sumLen;
int sticks[MAXN];
bool visited[MAXN];

bool rec(int curLen, int count) {
    if (curLen == sumLen / 4) {
        curLen = 0;
        count ++;
    }
    if (count == 3) return true;
    for (int i = 0; i < m; i ++) {
        if (curLen + sticks[i] <= sumLen / 4 && !visited[i]) {
//            cout << i << endl;
            visited[i] = true;
            if (rec(curLen + sticks[i], count)) return true;
            visited[i] = false;
        }
    }
//    cout << count << endl;
    return false;
}

int main() {
    scanf("%d", &n);
    while (n > 0) {
        scanf("%d", &m);
        sumLen = 0;
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < m; i ++) {
            scanf("%d", &sticks[i]);
            sumLen += sticks[i];
        }
        if (sumLen % 4 != 0) {
            cout << "no\n";
            n --;
            continue;
        }
        if (sticks[0] > sumLen / 4) {
            cout << "no\n";
            n --;
            continue;
        }
        visited[0] = true;
        if (rec(sticks[0], 0)) cout << "yes\n";
        else cout << "no\n";
        n --;
    }
    return 0;
}