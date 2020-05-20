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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int floor = INT_MAX;
        if (root -> left) floor = min(floor, minDepth(root -> left));
        if (root -> right) floor = min(floor, minDepth(root -> right));
        if (floor == INT_MAX) return 1;
        return floor + 1;
    }
};