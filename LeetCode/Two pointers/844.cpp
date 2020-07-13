//
// Created by Chengwei Zhang on 5/11/20.
//

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> ss;
        stack<char> st;
        for (int i = 0; i < S.size(); i ++) {
            char ch = S[i];
            if (ch != '#') ss.push(ch);
            else if (!ss.empty()) ss.pop();
        }
        for (int i = 0; i < T.size(); i ++) {
            char ch = T[i];
            if (ch != '#') st.push(ch);
            else if (!st.empty()) st.pop();
        }
        while (!ss.empty() && !st.empty()) {
            if (ss.top() != st.top()) return false;
            ss.pop();
            st.pop();
        }
        if (ss.empty() && st.empty()) return true;
        return false;
    }
};