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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        while (p != NULL && p -> next != NULL) {
            if (p -> next -> val == p -> val) {
                p -> next = p -> next -> next;
            }
            else {
                p = p -> next;
            }
        }
        return head;
    }
};