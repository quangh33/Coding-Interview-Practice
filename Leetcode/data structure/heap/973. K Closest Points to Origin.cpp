//
// Created by Hoang, Quang on 2019-08-16.
//

// https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:
    typedef pair<int, pair<int, int>> pii;

    int dis(int u, int v) {
        return u * u + v * v;
    }

    vector <vector<int>> kClosest(vector <vector<int>> &points, int K) {
        priority_queue <pii> q;
        for (int i = 0; i < points.size(); i++) {
            int u = points[i][0];
            int v = points[i][1];
            q.push(make_pair(dis(u, v), make_pair(u, v)));
            if (q.size() > K) q.pop();
        }

        vector <vector<int>> res;
        while (!q.empty()) {
            int u = q.top().second.first;
            int v = q.top().second.second;
            q.pop();
            res.push_back({u, v});
        }

        return res;
    }
};
