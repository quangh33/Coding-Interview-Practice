//
// Created by Hoang, Quang on 2019-08-23.
//

// https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    void push(deque<int> &q, int x) {
        while (!q.empty() && q.back() < x) q.pop_back();
        q.push_back(x);
    }

    vector<int> maxSlidingWindow(vector<int> &a, int k) {
        deque<int> q;
        int n = a.size();
        vector<int> res;
        if (n == 0) return res;

        for (int i = 0; i < k - 1; i++) {
            push(q, a[i]);
        }


        for (int i = k - 1; i < n; i++) {
            push(q, a[i]);
            // for(auto it = q.begin(); it != q.end(); it++) cout<<*it<<" ";
            cout << endl;

            res.push_back(q.front());
            if (a[i - k + 1] == q.front()) q.pop_front();
        }
        return res;
    }
};