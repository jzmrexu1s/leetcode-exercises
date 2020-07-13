//
// Created by Chengwei Zhang on 5/22/20.
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
    bool checkRange(TreeNode* root, long long l, long long r) {
        if (root == NULL) return true;
        return root -> val > l && root -> val < r && checkRange(root -> left, l, root -> val) && checkRange(root -> right, root -> val, r);
    }
    bool isValidBST(TreeNode* root) {
        return checkRange(root, LONG_MIN, LONG_MAX);
    }
};