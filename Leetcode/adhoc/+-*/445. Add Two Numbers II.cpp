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
    ListNode *res;
    int carry = 0;

    int len(ListNode *u) {
        int count = 0;
        while (u) {
            count++;
            u = u->next;
        }
        return count;
    }

    ListNode *addZero(ListNode *u, int n) {
        for (int i = 1; i <= n; i++) {
            ListNode *temp = new ListNode(0);
            temp->next = u;
            u = temp;
        }
        return u;
    }

    void add(ListNode *u, ListNode *v) {
        if (!u) return;
        add(u->next, v->next);
        int sum = (u->val + v->val + carry) % 10;
        carry = (u->val + v->val + carry) / 10;
        ListNode *temp = new ListNode(sum);
        temp->next = res;
        res = temp;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int n = len(l1);
        int m = len(l2);

        if (n < m) {
            l1 = addZero(l1, m - n);
        } else if (n > m) {
            l2 = addZero(l2, n - m);
        }

        add(l1, l2);
        if (carry != 0) {
            ListNode *temp = new ListNode(carry);
            temp->next = res;
            res = temp;
        }

        return res;
    }
};
