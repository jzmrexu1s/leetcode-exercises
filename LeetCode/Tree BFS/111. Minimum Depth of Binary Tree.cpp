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
        queue<TreeNode*> q;
        TreeNode* node;
        int floor = 1;
        int size;
        int i;
        q.push(root);
        while (1) {
            size = q.size();
            i = 0;
            while (i < size) {
                node = q.front();
                q.pop();
                if (node -> left) {
                    q.push(node -> left);
                    if (node -> right) q.push(node -> right);
                }
                else if (node -> right) q.push(node -> right);
                else return floor;
                i ++;
            }
            floor ++;
        }
        return floor;
    }
};