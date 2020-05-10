//
// Created by Chengwei Zhang on 5/10/20.
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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast -> next != NULL && fast -> next -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
            if (fast == slow) {
                ListNode *r = fast;
                ListNode *l = head;
                while (r != l) {
                    r = r -> next;
                    l = l -> next;
                }
                return r;
            }
        }
        return NULL;
    }
};