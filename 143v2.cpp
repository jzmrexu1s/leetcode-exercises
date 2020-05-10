//
// Created by Chengwei Zhang on 5/11/20.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL) return;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast -> next != NULL && fast -> next -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        ListNode *head2 = slow -> next;
        slow -> next = NULL;

        ListNode *p = head2;
        ListNode *pre = new ListNode(NULL, NULL);
        while (p != NULL) {
            ListNode *follow = p -> next;
            p -> next = pre;
            pre = p;
            p = follow;
        }

        // ListNode *test = head;
        // while (test != NULL) {
        //     cout << test -> val << ",";
        //     test = test -> next;
        // }
        // cout << endl;
        // test = pre;
        // while (test != NULL) {
        //     if (test -> val != NULL) cout << test -> val << ",";
        //     test = test -> next;
        // }

        ListNode *p1 = head;
        ListNode *p2 = pre;
        while (p1 != NULL && p2 != NULL && p2 -> val != NULL) {
            ListNode *follow1 = p1 -> next;
            ListNode *follow2 = p2 -> next;
            p1 -> next = p2;
            p2 -> next = follow1;
            p1 = follow1;
            p2 = follow2;
        }

    }
};