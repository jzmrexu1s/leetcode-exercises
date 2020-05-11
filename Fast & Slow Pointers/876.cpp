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
    ListNode* middleNode(ListNode* head) {
        if (head == NULL) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast -> next != NULL && fast -> next -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        if (fast -> next != NULL) {
            return slow -> next;
        }
        return slow;
    }
};