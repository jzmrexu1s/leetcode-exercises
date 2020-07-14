//
// Created by Chengwei Zhang on 7/14/20.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int* makeNext(int* p, int sz) {
    int* next = new int[sz];
    next[0] = 0;
    int x = 1;
    int now = 0;
    while (x < sz) {
        if (p[now] == p[x]) {
            now += 1;
            x += 1;
            next[x - 1] = now;
        }
        else if (now != 0) now = next[now - 1];
        else {
            next[x] = 0;
            x += 1;
        }
    }
    return next;
}

int match(int* s, int* p, int* next, int ssz, int psz) {
    int sc = 0;
    int pc = 0;
    while (sc < ssz) {
        if (s[sc] == p[pc]) {
            sc += 1;
            pc += 1;
        }
        else if (pc > 0) pc = next[pc - 1];
        else sc += 1;

        if (pc == psz) return sc - pc;
    }
    return -2;
}

int main() {
    int cases;
    scanf("%d", &cases);
    while (cases > 0) {
        int slen, plen;
        scanf("%d%d", &slen, &plen);
        int* s = new int[slen];
        int* p = new int[plen];
        for (int i = 0; i < slen; i ++) {
            int t;
            scanf("%d", &t);
            s[i] = t;
        }
        for (int i = 0; i < plen; i ++) {
            int t;
            scanf("%d", &t);
            p[i] = t;
        }
        int* next = makeNext(p, plen);
        cout << match(s, p, next, slen, plen) + 1 << endl;
        cases --;
    }
}