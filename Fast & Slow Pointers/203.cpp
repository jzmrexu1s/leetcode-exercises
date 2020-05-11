//
// Created by Chengwei Zhang on 5/11/20.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return head;
        ListNode* d = new ListNode(-1);
        d -> next = head;
        ListNode* slow = d;
        ListNode* fast = head;
        while (fast != NULL) {
            if (fast -> val == val) slow -> next = fast -> next;
            else slow = slow -> next;
            if (slow == NULL) fast = NULL;
            else fast = fast -> next;
        }
        return d -> next;
    }
};