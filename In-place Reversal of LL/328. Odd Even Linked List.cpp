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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head -> next == NULL) return head;
        ListNode* l = head;
        ListNode* second = head -> next;
        ListNode* r;
        ListNode* follow;
        bool isOdd = true;
        while (l != NULL && l -> next != NULL && l -> next -> next != NULL) {
            follow = l -> next;
            r = follow -> next;
            l -> next = r;
            l = follow;
            isOdd = !isOdd;
        }
        // cout << isOdd << "," << l -> next -> next;
        if (isOdd) {
            l -> next -> next = NULL;
            l -> next = second;
        }
        else {
            l -> next -> next = second;
            l -> next = NULL;
        }
        return head;
    }
};