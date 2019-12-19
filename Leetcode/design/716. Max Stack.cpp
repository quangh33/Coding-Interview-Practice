class MaxStack {
private:
    stack<int> s;
    stack<int> ma;
public:
    /** initialize your data structure here. */
    MaxStack() {

    }

    void push(int x) {
        s.push(x);
        int maxValue = ma.empty() ? x : ma.top();
        ma.push(max(x, maxValue));
    }

    int pop() {
        int x = s.top();
        s.pop();
        ma.pop();
        return x;
    }

    int top() {
        return s.top();
    }

    int peekMax() {
        return ma.top();
    }

    int popMax() {
        int x = ma.top();
        stack<int> buffer;
        while (!s.empty() && top() != x) buffer.push(pop());
        pop();
        while (!buffer.empty()) {
            push(buffer.top());
            buffer.pop();
        }
        return x;
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