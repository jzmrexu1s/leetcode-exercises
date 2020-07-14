//
// Created by Chengwei Zhang on 7/14/20.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        int res = 0;
        for (int i = 0; i < str1.size(); i ++) {
            for (int j = 0; j < str2.size(); j ++) {
                res += (str1[i] - '0') * (str2[j] - '0');
            }
        }
        cout << res << endl;
    }
    return 0;
}