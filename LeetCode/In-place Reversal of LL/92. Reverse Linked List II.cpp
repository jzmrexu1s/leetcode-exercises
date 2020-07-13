//
// Created by Chengwei Zhang on 5/18/20.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL) return head;
        ListNode* d = new ListNode(-1);
        d -> next = head;
        ListNode* pre = d;
        ListNode* cur;
        ListNode* leftBound;
        ListNode* rightBound;
        ListNode* follow;
        int l = n - m;
        while (m > 1) {
            pre = pre -> next;
            m --;
        }
        leftBound = pre;
        cur = pre -> next;
        rightBound = cur;
        while (l >= 0) {
            follow = cur -> next;
            cur -> next = pre;
            if (l == 0) leftBound -> next = cur;

            pre = cur;
            cur = follow;
            l --;
        }
        rightBound -> next = cur;
        return d -> next;
    }
};