//
// Created by Chengwei Zhang on 5/23/20.
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
private:
    vector<vector<int>> r;
    void rec(TreeNode* node, int remain, vector<int> trace) {
        if (node == NULL) return;
        if (node -> left == NULL && node -> right == NULL) {
            if (node -> val == remain) {
                trace.push_back(node -> val);
                r.push_back(trace);
            }
            return;
        }
        int val = node -> val;
        trace.push_back(val);
        rec(node -> left, remain - val, trace);
        rec(node -> right, remain - val, trace);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL) return r;
        vector<int> trace;
        rec(root, sum, trace);
        return r;
    }
};