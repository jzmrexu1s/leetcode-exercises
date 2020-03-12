//
// Created by Chengwei Zhang on 3/12/20.
//

/*
 * string（字符是数字）转int：char - '0'
 * vector末尾添加一个元素：vector.push_back()
 * 遍历vector：T i in vector<T>
 * 判断空串：string.empty()
 *
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> result;
    vector<vector<char>> phone = {{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
    void iter(string current, string remain) {
        if (remain.empty()) {
            result.push_back(current);
        }
        else {
            // char -> int
            int p = remain[0] - '0';

            for (char i : phone[p]) {
                iter(current + i, remain.substr(1));
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return result;
        }
        string s;
        iter(s, digits);
        return result;
    }
};

int main() {
    Solution solution;
    string s = "23";
    vector<string> result = solution.letterCombinations(s);
    for (const string &k : result) {
        cout << k << " ";
    }
}