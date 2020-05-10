//
// Created by Chengwei Zhang on 5/11/20.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rec(ListNode *head, int len) {
        if (len == 1) {
            ListNode *tail = head -> next;
            head -> next = NULL;
            return tail;
        }
        if (len == 2) {
            ListNode *tail = head -> next -> next;
            head -> next -> next = NULL;
            return tail;
        }
        ListNode *tail = rec(head -> next, len - 2);
        ListNode *tailRight = tail -> next;
        ListNode *headRight = head -> next;
        head -> next = tail;
        tail -> next = headRight;
        return tailRight;
    }
    void reorderList(ListNode* head) {
        int len = 0;
        if (head != NULL) {
            ListNode *p = head;
            while (p != NULL) {
                p = p -> next;
                len ++;
            }
            rec(head, len);
        }

    }
};