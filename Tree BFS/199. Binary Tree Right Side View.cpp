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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        deque<TreeNode*> q;
        TreeNode* t;
        int size = 1;
        int i;
        q.push_back(root);
        while (size != 0) {
            t = q.back();
            result.push_back(t -> val);
            i = 0;
            while (i < size) {
                t = q.front();
                if (t -> left) q.push_back(t -> left);
                if (t -> right) q.push_back(t -> right);
                q.pop_front();
                i ++;
            }
            size = q.size();
        }
        return result;
    }
};