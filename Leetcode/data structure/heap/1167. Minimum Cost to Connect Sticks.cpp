//
// Created by Hoang, Quang on 2019-11-21.
//

class Solution {
public:
    int connectSticks(vector<int> &a) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i: a) q.push(i);
        int res = 0;
        while (q.size() > 1) {
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            res = res + x + y;
            q.push(x + y);
        }
        return res;
    }
};