//
// Created by Chengwei Zhang on 5/24/20.
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode* l = invertTree(root -> right);
        TreeNode* r = invertTree(root -> left);
        root -> left = l;
        root -> right = r;
        return root;
    }
};