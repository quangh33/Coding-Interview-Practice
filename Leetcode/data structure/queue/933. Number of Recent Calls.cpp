//
// Created by Hoang, Quang on 2019-08-14.
//

// https://leetcode.com/problems/number-of-recent-calls/

class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
        q = queue<int>();
    }

    int ping(int t) {
        q.push(t);
        int bound = t - 3000;
        while (q.front() < bound) q.pop();
        return q.size();
    }
};