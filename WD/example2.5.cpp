//
// Created by Chengwei Zhang on 10/9/20.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
char colorMap[80][80];

int main() {
    int n;
    char in, out;
    while (scanf("%d %c %c", &n, &in, &out) != EOF) {
        memset(colorMap, ' ', sizeof(colorMap));
        int layer = 0;
        while (layer <= n / 2) {
            char cur = (n / 2 - layer) % 2 == 0 ? in : out;
            for (int i = layer; i < n - layer; i ++) {
                colorMap[i][layer] = cur;
                colorMap[i][n - 1 - layer] = cur;
                colorMap[layer][i] = cur;
                colorMap[n - 1 - layer][i] = cur;
            }
            layer ++;
        }
        if (n != 1) {
            colorMap[0][0] = ' ';
            colorMap[0][n - 1] = ' ';
            colorMap[n - 1][0] = ' ';
            colorMap[n - 1][n - 1] = ' ';
        }
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                printf("%c", colorMap[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}