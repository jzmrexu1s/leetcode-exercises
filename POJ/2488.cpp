//
// Created by Chengwei Zhang on 10/5/20.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;

bool visited[8][8];
int ops[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {-2, -1},
           {-1, -2}, {1, -2}, {2, -1}};
int p, q;

bool rec(int x, int y, int steps, string s) {
    if (steps == p * q) {
        cout << s << endl << endl;
        return true;
    }
    for (int i = 0; i < 8; i ++) {
        int newX = x + ops[i][0];
        int newY = y + ops[i][1];
        char col = newY + 'A';
        char row = newX + '1';
//        string st = "";
//        cout << st + col + row << newX << " " << newY << " " << visited[newX][newY] << endl;
        if (newX >= 0 && newX < p && newY >= 0 && newY < q && !visited[newX][newY]) {
            visited[newX][newY] = true;
//            cout << s + col + row << " " << steps << endl;
            if (rec(newX, newY, steps + 1, s + col + row)) return true;
            visited[newX][newY] = false;
        }
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    int i = 0;
    while (i < n) {
        scanf("%d%d", &p, &q);
        memset(visited, false, sizeof(visited));
        visited[0][0] = true;
        cout << "Scenario #" << i + 1 << ":" << endl;
        if (!rec(0, 0, 1, "A1")) {
            cout << "impossible" << endl << endl;
        }
        i ++;
    }
    return 0;
}