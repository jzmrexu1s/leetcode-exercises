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
        unordered_map<int, int> rightViewVal;
        stack<TreeNode*> nodeStack;
        stack<int> depthStack;
        int maxDepth = 0;
        TreeNode* tNode;
        int tDepth;
        nodeStack.push(root);
        depthStack.push(0);
        while (!nodeStack.empty()) {
            tNode = nodeStack.top();
            nodeStack.pop();
            tDepth = depthStack.top();
            depthStack.pop();
            if (tNode == NULL) continue;
            maxDepth = max(maxDepth, tDepth);
            if (rightViewVal.find(tDepth) == rightViewVal.end()) rightViewVal[tDepth] = tNode -> val;
            if (tNode -> left != NULL) {
                nodeStack.push(tNode -> left);
                depthStack.push(tDepth + 1);
            }
            if (tNode -> right != NULL) {
                nodeStack.push(tNode -> right);
                depthStack.push(tDepth + 1);
            }
        }
        for (int i = 0; i <= maxDepth; i ++) {
            result.push_back(rightViewVal[i]);
        }

        return result;
    }
};