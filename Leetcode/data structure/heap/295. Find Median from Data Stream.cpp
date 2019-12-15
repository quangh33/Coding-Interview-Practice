//
// Created by Hoang, Quang on 2019-12-15.
//

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> ma;
    priority_queue<int, vector<int>, greater<int>> mi;

    MedianFinder() {

    }

    void addNum(int num) {
        if (mi.size() == 0) {
            mi.push(num);
            return;
        }

        if (num > mi.top()) mi.push(num);
        else ma.push(num);

        if (mi.size() > ma.size() + 1) {
            int topMin = mi.top();
            mi.pop();
            ma.push(topMin);
        } else if (mi.size() < ma.size()) {
            int topMax = ma.top();
            ma.pop();
            mi.push(topMax);
        }
    }

    double findMedian() {
        if (mi.size() == ma.size()) return 0.5 * (mi.top() + ma.top());
        return mi.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */