//
// Created by Hoang, Quang on 2019-08-09.
//

// https://leetcode.com/problems/top-k-frequent-elements/
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
    typedef pair<int, int> II;
public:
    vector<int> topKFrequent(vector<int> &a, int k) {
        int n = a.size();
        priority_queue<II, vector<II>, greater<II>> q;
        unordered_map<int, int> count;

        for (int i: a) count[i]++;
        for (auto pair: count) {
            q.push(II(pair.second, pair.first));
            if (q.size() > k) q.pop();
        }

        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
