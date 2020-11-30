//
// Created by Chengwei Zhang on 10/24/20.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int main() {
    string rulesRaw;
    getline(cin, rulesRaw);
    int empty[5];
    int live[5];
    for (int i = 0; i < 5; i ++) empty[i] = rulesRaw[i] - '0';
    for (int i = 6; i < 11; i ++) live[i - 6] = rulesRaw[i] - '0';

    int m, n;
    scanf("%d %d", &m, &n);

    int** matrix = new int*[m];
    cin.ignore();
    for (int i = 0; i < m; i ++) {
        matrix[i] = new int[m];
        string s;
        getline(cin, s);
        for (int j = 0; j < m; j ++) {matrix[i][j] = s[j] - '0';}
    }



    int times = 0;
    while (times < n) {
        int** newMatrix = new int*[m];
        for (int i = 0; i < m; i ++) {
            newMatrix[i] = new int[m];
            for (int j = 0; j < m; j ++) {
                int checkUp = i == 0 ? m - 1 : i - 1;
                int checkDown = i == m - 1 ? 0 : i + 1;
                int checkLeft = j == 0 ? m - 1 : j - 1;
                int checkRight = j == m - 1 ? 0 : j + 1;
                int checkSum = matrix[checkUp][j] + matrix[checkDown][j] + matrix[i][checkLeft] + matrix[i][checkRight];
                if (matrix[i][j] == 0) {
                    if (empty[checkSum - 1] == 1) newMatrix[i][j] = 1;
                    else newMatrix[i][j] = 0;
                }
                else {
                    if (live[checkSum - 1] == 1) newMatrix[i][j] = 0;
                    else newMatrix[i][j] = 1;
                }
            }
        }
        matrix = newMatrix;
        times ++;
    }

    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < m; j ++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}