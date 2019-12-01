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
    typedef pair<int, ListNode*> ii;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* point = head;
        
        priority_queue<ii, vector<ii>, greater<ii>> q;
        
        for(ListNode* l: lists) 
            if (l) q.push(make_pair(l->val, l));
        
        while (!q.empty()) {
            ListNode* minNode = q.top().second;
            int minValue = q.top().first;
            q.pop();
            point->next = new ListNode(minValue);
            point = point->next;
            minNode = minNode->next;
            if (minNode) q.push(make_pair(minNode->val, minNode));
        }
        return head->next;
    }
};