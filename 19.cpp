//
// Created by Chengwei Zhang on 3/13/20.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        int len = 0;
        while (p != NULL) {
            len ++;
            p = p -> next;
        }
        if (n == len) {
            return head -> next;
        }
        else {
            p = head;
            int current = 0;
            ListNode* q;
            while (current != len - n - 1) {
                p = p -> next;
                current ++;
            }
            if (n == 1) {
                p -> next = NULL;
            }
            else {
                p -> next = p -> next -> next;
            }
        }
        return head;
    }
};