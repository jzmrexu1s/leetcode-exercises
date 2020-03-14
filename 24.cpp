//
// Created by Chengwei Zhang on 3/14/20.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* following = head -> next;
        if (following == NULL) return head;
        head -> next = swapPairs(following -> next);
        following -> next = head;
        return following;
    }
};