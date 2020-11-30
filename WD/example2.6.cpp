//
// Created by Chengwei Zhang on 10/9/20.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int y, m, d;
    while (scanf("%d%d%d", &y, &m, &d) != EOF) {
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) days[1] = 29;
        int r = 0;
        for (int i = 0; i < m - 1; i ++) {
            r += days[i];
        }
        r += d;
        printf("%d\n", r);
    }
    return 0;
}