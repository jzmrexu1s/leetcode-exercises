//
// Created by Chengwei Zhang on 7/16/20.
//

#include <iostream>
#include <cstdio>
#include <climits>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

bool testPa(string s) {
    int l = 0;
    int r = s.size() - 1;
    while (l != r) {
        if (s[l] != s[r]) return false;
        l ++;
        r --;
    }
    return true;
}

int main() {
    int count;
    scanf("%d", &count);
    while (count > 0) {
        string s;
        cin >> s;
        if (s.size() == 1) cout << "YES" << endl;
        else if (testPa(s)) cout << "YES" << endl;
        else cout << "NO" << endl;
        count --;
    }
    return 0;
}