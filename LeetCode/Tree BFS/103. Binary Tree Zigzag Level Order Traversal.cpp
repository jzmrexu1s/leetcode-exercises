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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> r;
        if (!root) return r;
        deque<TreeNode*> d;
        bool fromLeft = true;
        int size;
        int i;
        TreeNode* node;
        d.push_back(root);
        while (!d.empty()) {
            size = d.size();
            i = 0;
            deque<TreeNode*> tempd;
            r.push_back(vector<int> {});
            if (fromLeft) {
                while (i < size) {
                    node = d.back();
                    d.pop_back();
                    if (node -> left) tempd.push_front(node -> left);
                    if (node -> right) tempd.push_front(node -> right);
                    r.back().push_back(node -> val);
                    i ++;
                }
            }
            else {
                while (i < size) {
                    node = d.front();
                    d.pop_front();
                    if (node -> right) tempd.push_back(node -> right);
                    if (node -> left) tempd.push_back(node -> left);
                    r.back().push_back(node -> val);
                    i ++;
                }
            }
            fromLeft = !fromLeft;
            d = tempd;
        }
        return r;
    }
};