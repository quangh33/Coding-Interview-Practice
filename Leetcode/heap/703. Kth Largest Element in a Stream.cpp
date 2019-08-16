//
// Created by Hoang, Quang on 2019-08-16.
//

// https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int K;
    KthLargest(int k, vector<int>& a) {
        K = k;
        for(int i: a) add(i);
    }

    int add(int val) {
        if (q.size() < K || q.top() < val) q.push(val);
        if (q.size() > K) q.pop();
        return q.top();
    }
};

