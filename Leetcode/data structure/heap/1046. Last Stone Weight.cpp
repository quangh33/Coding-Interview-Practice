//
// Created by Hoang, Quang on 2019-08-16.
//

// https://leetcode.com/problems/last-stone-weight/

int lastStoneWeight(vector<int>& a) {
    priority_queue<int> q;
    for(int i: a) q.push(i);
    while (q.size() > 1) {
        int top = q.top();
        q.pop();
        int secondTop = q.top();
        q.pop();
        if (top > secondTop) q.push(top - secondTop);
    }
    return q.size() == 0 ? 0 : q.top();
}

