//
// Created by Chengwei Zhang on 5/20/20.
//

/*
 *  队列
 *  q.empty()               如果队列为空返回true，否则返回false
 *  q.size()                返回队列中元素的个数
 *  q.pop()                 删除队列首元素但不返回其值
 *  q.front()               返回队首元素的值，但不删除该元素
 *  q.push()                在队尾压入新元素
 *  q.back()                返回队列尾元素的值，但不删除该元素
 */

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> r;
        TreeNode* p;
        int size;
        int i = 0;
        if (!root) return r;
        q.push(root);
        while (!q.empty()) {
            vector<int> t = {};
            r.push_back(t);
            size = q.size();
            i = 0;
            while (i < size) {
                p = q.front();
                q.pop();
                if (p -> left) q.push(p -> left);
                if (p -> right) q.push(p -> right);
                r.back().push_back(p -> val);
                i ++;
            }
        }
        return r;

    }
};