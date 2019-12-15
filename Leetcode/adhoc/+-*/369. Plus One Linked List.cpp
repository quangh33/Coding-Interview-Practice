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
    ListNode *res = NULL;
    int carry = 1;

    void add(ListNode *a) {
        if (!a) return;
        add(a->next);
        int sum = (a->val + carry) % 10;
        carry = (a->val + carry) / 10;
        ListNode *temp = new ListNode(sum);
        temp->next = res;
        res = temp;
    }

    ListNode *plusOne(ListNode *head) {
        add(head);
        if (carry != 0) {
            ListNode *temp = new ListNode(carry);
            temp->next = res;
            res = temp;
        }
        return res;
    }
};
