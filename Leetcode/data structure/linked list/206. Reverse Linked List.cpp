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
    ListNode* reverse(ListNode* u, ListNode* p) {
        if (!u->next) {
            u->next = p;
            return u;
        }
        ListNode* next = u->next;
        u->next = p;
        return reverse(next, u);
    }
    
    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return head;
        return reverse(head, NULL);
    }
};