//
// Created by Hoang, Quang on 2019-12-15.
//

class MaxStack {
public:
    /** initialize your data structure here. */
    list<int> l;
    map<int, stack<list<int>::iterator>> m;

    MaxStack() {

    }

    void push(int x) {
        l.push_back(x);
        if (m.count(x) == 0) m[x] = stack<list<int>::iterator>();
        m[x].push(l.end());
    }

    int pop() {
        int last = l.back();
        l.pop_back();
        m[last].pop();
        if (m[last].empty()) m.erase(last);
        return last;
    }

    int top() {
        return l.back();
    }

    int peekMax() {
        return m.begin()->first;
    }

    int popMax() {
        int ma = peekMax();
        l.erase(m[ma].top());
        m[ma].pop();
        if (m[ma].empty()) m.erase(ma);
        return ma;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */