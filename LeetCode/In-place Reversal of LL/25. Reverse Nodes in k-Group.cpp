//
// Created by Chengwei Zhang on 5/17/20.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return head;
        ListNode* d = new ListNode(-1);
        d -> next = head;
        int count = 0;
        ListNode* p = head;
        ListNode* fin;
        while (p != NULL) {
            if (count == k - 1) {
                fin = p;
            }
            count ++;
            p = p -> next;
        }
        int curCount = 1;
        int tmpCount = 1;
        ListNode* pre = d;
        ListNode* cur = pre -> next;
        ListNode* follow;
        ListNode* lastFirst = NULL;
        ListNode* thisFirst = NULL;
        int endNum = (count / k) * k;
        // cout << endNum << endl;
        while (curCount <= endNum) {
            // cout << curCount << ' ';
            tmpCount = 1;
            thisFirst = cur;
            while (tmpCount <= k) {
                follow = cur -> next;
                cur -> next = pre;
                if (tmpCount == k && lastFirst != NULL) {
                    // cout << lastFirst -> val << "," << cur -> val;
                    lastFirst -> next = cur;
                }
                pre = cur;
                cur = follow;
                curCount ++;
                tmpCount ++;

            }
            lastFirst = thisFirst;
        }
        lastFirst -> next = cur;
        return fin;
    }
};