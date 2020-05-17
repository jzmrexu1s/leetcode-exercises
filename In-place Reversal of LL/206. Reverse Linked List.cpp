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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return head;
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* follow;
        while (cur != NULL) {
            follow = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = follow;
        }
        return pre;
    }
};