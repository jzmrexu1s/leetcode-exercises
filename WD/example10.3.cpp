//
// Created by Chengwei Zhang on 10/6/20.
//

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) {
        val = v;
        left = NULL;
        right = NULL;
    }
};

void insert(TreeNode* root, int newVal) {
    if (newVal < root -> val) {
        if (root -> left) insert(root -> left, newVal);
        else {
            cout << root -> val << endl;
            root -> left = new TreeNode(newVal);
        }
    }
    else if (newVal > root -> val) {
        if (root -> right) insert(root -> right, newVal);
        else {
            cout << root -> val << endl;
            root -> right = new TreeNode(newVal);
        }
    } ;
}

int main() {
    int n;
    scanf("%d", &n);
    int i = 0;
    scanf("%d", &i);
    TreeNode* root = new TreeNode(i);
    cout << "-1" << endl;
    while (scanf("%d", &i) != EOF) {
        insert(root, i);
    }
    return 0;
}