//
// Created by Chengwei Zhang on 5/8/20.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        ListNode* d = new ListNode{0};
        d -> next = head;
        ListNode* slow = d;
        ListNode* fast;
        while (slow != NULL && slow -> next != NULL) {
            fast = slow -> next;
            if (fast -> next == NULL) break;
            if (fast -> next -> val == fast -> val) {
                while (fast -> next != NULL && fast -> next -> val == fast -> val) {
                    fast = fast -> next;
                }
                fast = fast -> next;
                slow -> next = fast;
            } else {
                slow = slow -> next;
            }
        }
        return d -> next;
    }
};