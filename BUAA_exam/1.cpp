//
// Created by Chengwei Zhang on 10/10/20.
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <cctype>

using namespace std;

struct Func {
    string name;
    vector<string> args;
};

bool checkValidFun(char c) {
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
    return c == '_' || c == '~' || c == '$';
}

string cleanSpace(string s) {
    int i = 0;
    string st;
    while (i < s.size()) {
        if (s[i] != ' ') {
            st += s[i];
        }
        i ++;
    }
    return st;
}

int main() {
    string s;
    getline(cin, s);
    vector<Func> r;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == '(') {
            Func newF;

            int j = i;
            while (!checkValidFun(s[j])) j --;
            int nameRight = j;
            while (checkValidFun(s[j])) j --;
            int nameLeft = j;
            newF.name = s.substr(nameLeft + 1,  nameRight - nameLeft);

            j = i;
            int argLeft = j + 1;
            while (s[j] != ')') {
                if (s[j] == ',') {
                    string tmp = s.substr(argLeft, j - argLeft);
                    newF.args.push_back(cleanSpace(tmp));
                    argLeft = j + 1;
                }
                j ++;
            }
            string tmp = s.substr(argLeft, j - argLeft);
            newF.args.push_back(cleanSpace(tmp));
            r.push_back(newF);
        }
    }
    for (int i = 0; i < r.size(); i ++) {
        cout << r[i].name << " ";
        for (int j = 0; j < r[i].args.size(); j ++) {
            cout << r[i].args[j] << " ";
        }
        cout << endl;
    }

    return 0;
}