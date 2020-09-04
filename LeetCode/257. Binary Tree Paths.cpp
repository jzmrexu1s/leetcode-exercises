//
// Created by Chengwei Zhang on 9/4/20.
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
    vector<string> res;
    void rec(TreeNode* root, string s) {
        if (root == NULL) return;
        if (root -> left == NULL && root -> right == NULL) {
            s = s + to_string(root -> val);
            res.push_back(s);
            return;
        }
        s = s + to_string(root -> val) + "->";
        rec(root -> left, s);
        rec(root -> right, s);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) return res;
        string s;
        rec(root, s);
        return res;
    }
};