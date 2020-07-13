//
// Created by Chengwei Zhang on 3/13/20.
//

/*
 * 思路：
 * 要找到需要被删除的节点的前一个节点。
 * 如果要被删除的节点是head，则它没有前一个节点。
 * 因此，通过dummy节点（指向head）来解决。
 *
 * 然后使用双指针，都从dummy节点出发。
 * 将第一个指针向前n + 1步，然后停止。
 * 同时移动两个指针，直到第一个指针移动到尾节点为止。
 * 此时，第二个指针指向的就是要被删除的节点的前一个节点。
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        for (int i = 1; i <= n + 1; i ++) {
            fast = fast -> next;
        }
        if (fast == NULL) {
            return head -> next;
        }
        while (fast != NULL) {
            fast = fast -> next;
            slow = slow -> next;
        }
        slow -> next = slow -> next -> next;
        return head;
    }
};