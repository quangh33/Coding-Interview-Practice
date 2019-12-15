//
// Created by Hoang, Quang on 2019-08-09.
//

// https://leetcode.com/problems/top-k-frequent-elements/
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        int n = a.size();
        unordered_map<int, int> count;
        for(int i: a) count[i]++;
        priority_queue<pair<int, int>> q;

        unordered_map<int, int>:: iterator p;
        for (p = count.begin(); p != count.end(); p++) {
            q.push(make_pair(p->second, p->first));
        }

        vector<int> res;

        while (!q.empty()) {
            res.push_back(q.top().second);
            k--;
            if (k == 0) break;
            q.pop();
        }
        return res;
    }
};
