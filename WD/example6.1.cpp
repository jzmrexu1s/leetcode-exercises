//
// Created by Chengwei Zhang on 7/15/20.
//

#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    unsigned int num;
    while (scanf("%d", &num) != EOF) {
        vector<int> r;
        while (num != 0) {
            r.push_back(num % 2);
            num = num / 2;
        }
        bool topZero = true;
        for (int i = r.size() - 1; i >= 0; i --) {
            if (r[i] == 1) topZero = false;
            if (!(r[i] == 0 && topZero == true)) printf("%d", r[i]);
        }
        printf("\n");
    }
}