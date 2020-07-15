//
// Created by Chengwei Zhang on 7/16/20.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        if (n < 2) {
            cout << "no" << endl;
            continue;
        }
        int right = (int)sqrt((float)n);
        bool isSu = true;
        for (int i = 2; i <= right; i ++) {
            if (n % i == 0) {
                isSu = false;
                break;
            }
        }
        if (isSu) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}