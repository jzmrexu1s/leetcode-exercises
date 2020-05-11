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
    ListNode* front;

    bool rec(ListNode* head) {
        if (head) {
            if (!rec(head -> next)) return false;
            if (front -> val != head -> val) return false;
            front = front -> next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        front = head;
        return rec(head);
    }
};