//
// Created by Chengwei Zhang on 3/15/20.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        if (s.length() == 1) return 1;
        int l = 0;
        int r = 0;
        int maxLen = 0;
        while (r < s.length() - 1) {
            for (int i = l; i <= r; i ++) {
                if (s[i] == s[r + 1]) {
                    l = i + 1;
                    break;
                }
            }
            r ++;
            if (r - l + 1 > maxLen) maxLen = r - l + 1;
        }
        return maxLen;
    }
};
int main() {
    Solution solution;
    int r = solution.lengthOfLongestSubstring("abcabcbb");
    cout << r << endl;
}