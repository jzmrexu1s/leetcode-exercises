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
    int r;
    int rec(TreeNode* root) {
        if (root == NULL) return 0;
        if (root -> left == NULL && root -> right == NULL) {
            r = max(root -> val, r);
            return root -> val;
        }
        int leftMax = max(rec(root -> left), 0);
        int rightMax = max(rec(root -> right), 0);
        r = max(r, leftMax + rightMax + root -> val);
        return max(leftMax, rightMax) + root -> val;
    }
public:
    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;
        r = INT_MIN;
        rec(root);
        return r;
    }
};