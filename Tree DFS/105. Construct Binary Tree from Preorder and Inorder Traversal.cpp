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
    unordered_map<int, int> ins;
public:
    TreeNode* rec(int preL, int preR, int inL, int inR, vector<int>& preorder, vector<int>& inorder) {
        if (inL > inR) return NULL;
        int inMidVal = preorder[preL];
        int inMid = ins[inMidVal];
        int leftLen = inMid - inL;
        TreeNode* root = new TreeNode(inMidVal);
        root -> left = rec(preL + 1, preL + 1 + leftLen, inL, inMid - 1, preorder, inorder);
        root -> right = rec(preL + 1 + leftLen, preR, inMid + 1, inR, preorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        int size = preorder.size();
        if (size == 0) return root;
        for (int i = 0; i < size; i ++) ins[inorder[i]] = i;
        return rec(0, size - 1, 0, size - 1, preorder, inorder);
    }
};