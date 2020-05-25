//
// Created by Chengwei Zhang on 5/25/20.
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
    TreeNode* rec(TreeNode* root, int p, int q) {
        if (root == NULL) return root;
        if (root -> val >= p && root -> val <= q) return root;
        else if (root -> val >= p) return rec(root -> left, p, q);
        else return rec(root -> right, p, q);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return root;
        TreeNode* r;
        if (p -> val < q -> val) r = rec(root, p -> val, q -> val);
        else r = rec(root, q -> val, p -> val);
        return r;
    }
};