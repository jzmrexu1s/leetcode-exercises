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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head -> next == NULL) return head;
        ListNode* mid = cut(head);
        ListNode* leftHead = sortList(head);
        ListNode* rightHead = sortList(mid);
        ListNode* mergedHead = merge(leftHead, rightHead);
        return mergedHead;
    }
private:
    ListNode* cut(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast -> next != NULL && fast -> next -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        ListNode* follow = slow -> next;
        slow -> next = NULL;
        // ListNode* test = head;
        // while (test != NULL) {
        //     cout << test -> val << ",";
        //     test = test -> next;
        // }
        // cout << endl;
        // test = follow;
        // while (test != NULL) {
        //     cout << test -> val << ",";
        //     test = test -> next;
        // }
        // cout << endl;
        return follow;
    }
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* head0 = new ListNode(NULL);
        ListNode* p0 = head0;
        ListNode* p1 = head1;
        ListNode* p2 = head2;
        while (p1 != NULL && p2 != NULL) {
            if (p1 -> val >= p2 -> val) {
                p0 -> next = p2;
                p2 = p2 -> next;
            }
            else {
                p0 -> next = p1;
                p1 = p1 -> next;
            }
            p0 = p0 -> next;
        }
        while (p1 != NULL) {
            p0 -> next = p1;
            p1 = p1 -> next;
            p0 = p0 -> next;
        }
        while (p2 != NULL) {
            p0 -> next = p2;
            p2 = p2 -> next;
            p0 = p0 -> next;
        }
        return head0 -> next;
    }
};