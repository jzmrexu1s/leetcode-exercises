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
    TreeNode* r;
    bool rec(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return false;
        bool hasL = rec(root -> left, p, q);
        bool hasR = rec(root -> right, p, q);
        if (((hasL || hasR) && (root -> val == p -> val || root -> val == q -> val)) || (hasL && hasR)) r = root;
        return hasL || hasR || (root -> val == p -> val || root -> val == q -> val);

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        rec(root, p, q);
        return r;
    }
};