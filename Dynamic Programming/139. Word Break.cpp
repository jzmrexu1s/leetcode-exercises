//
// Created by Chengwei Zhang on 7/4/20.
//

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for (int i = 0; i < wordDict.size(); i ++) {
            set.insert(wordDict[i]);
        }
        bool* dp = new bool[s.size() + 1]{false};
        dp[0] = true;
        for (int i = 1; i <= s.size(); i ++) {
            for (int j = 0; j < i; j ++) {
                if (dp[j] == true && set.find(s.substr(j, i - j)) != set.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};