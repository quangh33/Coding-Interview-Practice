#include<iostream>

#include<vector>
#include<queue>

using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int K;

    KthLargest(int k, vector<int> &a) {
        K = k;
        for(int i: a) add(i);
    }

    int add(int val) {
        if (q.size() < K || val > q.top()) q.push(val);
        if (q.size() > K) q.pop();
        return q.top();
    }
};


int main() {
    vector<int> a = { 4,5 };
    KthLargest* obj = new KthLargest(3, a);
    cout<< obj->add(3);
    return 0;
}