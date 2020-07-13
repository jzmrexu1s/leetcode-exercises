//
// Created by Chengwei Zhang on 5/25/20.
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
    unordered_map<int, TreeNode*> ances;
    unordered_map<int, bool> visited;
    int count;
    void rec(TreeNode* root, int p, int q) {
        if (count == 0 || root == NULL) return;
        if (root -> left != NULL) {
            int val = root -> left -> val;
            ances[val] = root;
            if (val == p || val == q) count --;
            rec (root -> left, p, q);
        }
        if (root -> right != NULL) {
            int val = root -> right -> val;
            ances[val] = root;
            if (val == p || val == q) count --;
            rec (root -> right, p, q);
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        count = 2;
        rec(root, p -> val, q -> val);
        TreeNode* cur = p;
        int val;
        while (1) {
            val = cur -> val;
            visited[val] = true;
            if (val == root -> val) break;
            cur = ances[cur -> val];
        }
        cur = q;
        while (1) {
            if (visited.find(cur -> val) != visited.end()) return cur;
            cur = ances[cur -> val];
        }
    }
};