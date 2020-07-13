//
// Created by Chengwei Zhang on 5/20/20.
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        queue<Node*> q;
        root -> next = NULL;
        int size = 1;
        int i;
        Node* node;
        Node* follow;
        q.push(root);
        while (size != 0) {
            i = 0;
            queue<Node*> qTemp;
            while (i < size) {
                node = q.front();
                q.pop();
                if (q.empty()) node -> next = NULL;
                else node -> next = q.front();
                if (node -> left) qTemp.push(node -> left);
                if (node -> right) qTemp.push(node -> right);
                i ++;
            }
            q = qTemp;
            size = q.size();
        }
        return root;
    }
};