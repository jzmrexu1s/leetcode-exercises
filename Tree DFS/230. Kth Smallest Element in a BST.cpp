//
// Created by Chengwei Zhang on 5/24/20.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<int>& rec(TreeNode* node, vector<int>& vals) {
        if (node == NULL) return vals;
        rec(node -> left, vals);
        vals.push_back(node -> val);
        rec(node -> right, vals);
        return vals;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vals;
        vector<int> r = rec(root, vals);
        return r[k - 1];
    }
};