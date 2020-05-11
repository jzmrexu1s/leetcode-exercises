//
// Created by Chengwei Zhang on 3/15/20.
//

/*
 * 思路：
 * 使用滑动窗口。
 * 右指针每次右移一位。
 * 如果右指针要右移到的那一位已经在当前的滑动窗口出现，
 * 那么将左指针移动到那一位在滑动窗口中的位置的右边一位。
 * 使用左闭右开区间可以一定程度上简化过程，
 * 即左指针指向的字符包含在滑动窗口中，
 * 而右指针指向的字符是即将需要判断是否已经出现在滑动窗口中的那一位。
 *
 * 关于如何判断某个字符是否已经在滑动窗口中出现：
 * 方法一：使用循环判断。
 * 方法二：使用hashmap。
 * 方法三：使用桶。
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.length();
        if (size == 0) return 0;
        if (size == 1) return 1;
        int l = 0;
        int r = 0;
        int maxLen = 0;
        unordered_map<char, int> hash;
        vector<int> vec(128, -1);
        while (r < size) {
//            Using basic method
//            for (int i = l; i < r; i ++) {
//                if (s[i] == s[r]) {
//                    l = i + 1;
//                    break;
//                }
//            }

//            Using hashmap
//            char tmpChar = s[r];
//            if (hash.find(tmpChar) != hash.end() && hash[tmpChar] >= l) {
//                l = hash[tmpChar] + 1;
//            }
//            hash[tmpChar] = r;


//            Using bucket
            char tmpChar = s[r];
            if (vec[int(tmpChar)] >= l) {
                l = vec[int(tmpChar)] + 1;
            }
            vec[tmpChar] = r;

            r ++;
            if (r - l > maxLen) maxLen = r - l;
        }
        return maxLen;
    }
};

int main() {
    Solution solution;
    int r = solution.lengthOfLongestSubstring("abcabcbb");
    cout << r << endl;
}