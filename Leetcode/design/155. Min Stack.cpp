//
// Created by Hoang, Quang on 2019-08-13.
//

// https://leetcode.com/problems/min-stack/

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> m;

    MinStack() {
        s = stack<int>();
        m = stack<int>();
    }

    void push(int x) {
        s.push(x);
        if (m.empty() || x <= m.top()) m.push(x);
    }

    void pop() {
        if (s.top() == m.top()) m.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return m.top();
    }
};