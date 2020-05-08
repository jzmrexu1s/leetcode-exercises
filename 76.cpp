//
// Created by Chengwei Zhang on 5/5/20.
//

/*

 */

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* slow = head;
        if (!slow) return head;
        ListNode* fast = slow -> next;
        if (!fast) return head;
        while (fast != NULL) {
            while (fast != NULL && fast -> val == slow -> val) {
                fast = fast -> next;
            }
            slow -> next = fast;
            slow = slow -> next;
            if (slow != NULL) {
                fast = slow -> next;
            }
        }
        return head;
    }
};