//
// Created by Chengwei Zhang on 7/16/20.
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int** matrixMul(int** m1, int **m2, int rows, int columns) {
    int ** res = new int*[rows];
    for (int i = 0; i < rows; i ++) {
        res[i] = new int[columns];
        for (int j = 0; j < columns; j ++) {
            res[i][j] = 0;
            for (int k = 0; k < rows; k ++) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return res;
}

int** fastMul(int** m, int n, int k) {
    int ** res = new int*[n];
    for (int i = 0; i < n; i ++) {
        res[i] = new int[n];
        for (int j = 0; j < n; j ++) {
            if (i == j) res[i][i] = 1;
            else res[i][j] = 0;
        }
    }

    int ** muler = m;

    while (k > 0) {
        if (k % 2 == 1) {
            res = matrixMul(res, muler, n, n);
        }
        k = k / 2;
        muler = matrixMul(muler, muler, n, n);
    }

    return res;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int** matrix = new int*[n];
    for (int i = 0; i < n; i ++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j ++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int** res = fastMul(matrix, n, k);
    for (int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}