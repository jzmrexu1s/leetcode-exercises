//
// Created by Chengwei Zhang on 7/14/20.
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        for (int i = 0; i < s.size(); i ++) {
            if ((s[i] >= 'a' && s[i] <= 'y') || (s[i] >= 'A' && s[i] <= 'Y')) {
                s[i] = s[i] + 1;
            }
            else if (s[i] == 'z') s[i] = 'a';
            else if (s[i] == 'Z') s[i] = 'A';
        }
        cout << s << endl;
    }
    return 0;
}