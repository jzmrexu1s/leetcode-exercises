//
// Created by Chengwei Zhang on 5/17/20.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        int len = 1;
        ListNode* p = head;
        while (p != NULL && p -> next != NULL) {
            len ++;
            p = p -> next;
        }
        // cout << p -> val << endl;
        p -> next = head;
        // cout << p -> next -> val << endl;
        int shift = len - k % len;
        p = head;
        while (shift > 0) {
            p = p -> next;
            shift --;
        }
        ListNode *start = p;
        // cout << p -> val << endl;
        while (len > 1) {
            p = p -> next;
            len --;
        }
        p -> next = NULL;
        return start;

    }
};