//
// Created by Chengwei Zhang on 5/5/20.
//

/*

 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        if (s.size() == 0 || t.size() == 0 || s.size() < t.size()) {
            return "";
        }

        int formed = 0;
        int l = 0;
        int r = 0;
        unordered_map<char, int> req;
        unordered_map<char, int> current;
        int minl = 0;
        int minr = s.size();
        bool found = false;

        // 初始化hashmap
        for (int i = 0; i < t.size(); i ++) {
            current[t[i]] = 0;
        }
        for (int i = 0; i < t.size(); i ++) {
            if (req.find(t[i]) != req.end()) {
                req[t[i]] ++;
            } else {
                req[t[i]] = 1;
            }
        }

        for (; r < s.size(); r ++) {
            // 找到相同字母，更新hashmap
            char ch = s[r];
            if (req.find(ch) != req.end()) {
                current[ch] += 1;
                if (current[ch] == req[ch]) {
                    formed ++;
                }
            }
//            cout << "A" << l << "," << r << endl;
            // 处理已经包括全部字母的情况
            if (formed == req.size()) {
                // 从左到右缩小范围，更新hashmap
                while (formed == req.size()) {
                    found = true;
                    char chl = s[l];
                    if (req.find(chl) != req.end()) {
                        current[chl] -= 1;
                        if (current[chl] < req[chl]) {
                            formed --;
                        }
                        if (r - l < minr - minl) {
                            minl = l;
                            minr = r;
//                            cout << "min" << l << "," << r << endl;
                        }
                    }
//                    cout << "B" << l << "," << r << endl;
                    l ++;
                }
            }
        }
        if (!found) return "";
        return s.substr(minl, minr - minl + 1);

    }
};

int main() {
    Solution solution;
    string s = "aa";
    string t = "aa";
    string r = solution.minWindow(s, t);
    cout << "result: " << r << endl;
}