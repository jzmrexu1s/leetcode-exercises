//
// Created by Chengwei Zhang on 5/20/20.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> r;
        TreeNode* p;
        int size;
        int i = 0;
        if (!root) return r;
        q.push(root);
        while (!q.empty()) {
            vector<int> t = {};
            r.push_back(t);
            size = q.size();
            i = 0;
            while (i < size) {
                p = q.front();
                q.pop();
                if (p -> left) q.push(p -> left);
                if (p -> right) q.push(p -> right);
                r.back().push_back(p -> val);
                i ++;
            }
        }
        return r;

    }
};