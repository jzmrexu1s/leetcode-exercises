//
// Created by Chengwei Zhang on 7/16/20.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

string res;

struct Node{
    char data;
    Node* left;
    Node* right;
    Node(char v) {
        data = v;
        left = NULL;
        right = NULL;
    }
};

Node* makeTree(string s, int& pos) {
    if (pos >= (int)s.size()) return NULL;
    if (s[pos] == '#') {
        pos ++;
        return NULL;
    }
    Node* root = new Node(s[pos]);
    pos ++;
    root -> left = makeTree(s, pos);
    root -> right = makeTree(s, pos);
    return root;
}

void traverse(Node* root) {
    if (root == NULL) return;
    traverse(root -> left);
    res += root -> data;
    traverse(root -> right);
    return;
}

int main() {
    string s;
    cin >> s;
    res = "";
    int pos = 0;
    Node* root = makeTree(s, pos);
    traverse(root);
    for (int i = 0; i < res.size(); i ++) {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}