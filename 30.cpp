//
// Created by Chengwei Zhang on 3/18/20.
//

/*
 * 初始化hashmap：unordered_map<T, T> map;
 * 向hashmap中增加：map[foo] = bar;
 * 查找某个元素是否在hashmap中：if(map.find(foo) == map.end());
 * 清空hashmap：map.clear();
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s == "") return result;
        unordered_map<string, int> hash;
        int wordsLen = words.size();
        if (wordsLen == 0) return result;
        int minLen = words[0].size();
        if (s.size() < minLen * wordsLen) return result;
        for (string word : words) {
            if (hash.find(word) == hash.end()) hash[word] = 1;
            else hash[word] ++;
        }
        unordered_map<string, int> tmpHash;
        for (int i = 0; i <= s.size() - minLen * wordsLen; i ++) {
            bool good = true;
            string sub = s.substr(i, minLen * wordsLen);
            int j = 0;
            while (j < minLen * wordsLen) {
                string minSub = sub.substr(j, minLen);
                if (hash.find(minSub) != hash.end()) {
                    if (tmpHash.find(minSub) == tmpHash.end()) tmpHash[minSub] = 1;
                    else if (tmpHash[minSub] == hash[minSub]) {
                        good = false;
                        j += minLen;
                        break;
                    }
                    else tmpHash[minSub] ++;
                }
                else {
                    good = false;
                    j += minLen;
                    break;
                }
                j += minLen;
            }
            if (good) result.push_back(i);
            tmpHash.clear();
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> s {"bar","foo","the"};
    vector<int> r = solution.findSubstring("barfoofoobarthefoobarman", s);
    for (int i : r) {
        cout << i << ", ";
    }
}