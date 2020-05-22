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
    bool rec(TreeNode* root, int remain) {
        if (root == NULL) return false;
        if (root -> left == NULL && root -> right == NULL) {
            if (remain == root -> val) return true;
            return false;
        }
        return rec(root -> left, remain - root -> val) || rec(root -> right, remain - root -> val);

    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        return rec(root, sum);
    }
};