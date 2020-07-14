//
// Created by Chengwei Zhang on 7/14/20.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

int p[10000];
int s[1000000];
int nxt[10000];

using namespace std;

int* makeNext(int sz) {
    nxt[0] = 0;
    int x = 1;
    int now = 0;
    while (x < sz) {
        if (p[now] == p[x]) {
            now += 1;
            x += 1;
            nxt[x - 1] = now;
        }
        else if (now != 0) now = nxt[now - 1];
        else {
            nxt[x] = 0;
            x += 1;
        }
    }
}

int match(int ssz, int psz) {
    int sc = 0;
    int pc = 0;
    while (sc < ssz && pc < psz) {
        if (s[sc] == p[pc]) {
            sc += 1;
            pc += 1;
        }
        else if (pc > 0) pc = nxt[pc - 1];
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
        makeNext(plen);
        cout << match(slen, plen) + 1 << endl;
        cases --;
    }
}

