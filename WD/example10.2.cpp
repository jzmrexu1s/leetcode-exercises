//
// Created by Chengwei Zhang on 10/6/20.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char v) {
        val = v;
        left = NULL;
        right = NULL;
    }
};

TreeNode* rec(string preSub, string midSub) {
    if (preSub.size() == 0) return NULL;
    char rootCh = preSub[0];
    int rootMidPos = midSub.find(preSub[0]);
    TreeNode* root = new TreeNode(rootCh);
    root -> left = rec(preSub.substr(1, rootMidPos), midSub.substr(0, rootMidPos));
    root -> right = rec(preSub.substr(rootMidPos + 1), midSub.substr(rootMidPos + 1));
    return root;
}

void recPost(TreeNode* root) {
    if (root == NULL) return;
    recPost(root -> left);
    recPost(root -> right);
    cout << root -> val;
}

int main() {
    string pre, mid;
    while (cin >> pre >> mid) {
        TreeNode* root = rec(pre, mid);
        recPost(root);
        cout << endl;
    }
    return 0;
}