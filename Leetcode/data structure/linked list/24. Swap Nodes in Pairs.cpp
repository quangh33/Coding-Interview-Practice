//
// Created by Hoang, Quang on 2019-12-15.
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
    ListNode *swapPairs(ListNode *head) {
        if (!head) return head;
        if (!head->next) return head;
        ListNode *res = head->next;

        ListNode *a = head;
        ListNode *b = a->next;

        while (true) {
            ListNode *c = b->next;
            ListNode *d = c ? c->next : NULL;

            a->next = d ? d : c;
            b->next = a;
            a = c;
            if (!a) break;
            b = d;
            if (!b) break;
        }
        return res;
    }
};