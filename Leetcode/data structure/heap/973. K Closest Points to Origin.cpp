//
// Created by Hoang, Quang on 2019-08-16.
//

// https://leetcode.com/problems/k-closest-points-to-origin/

typedef pair<int, pair<int, int>> pii;

int dis(int u, int v) {
    return u * u + v * v;
}

vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (int i = 0; i < points.size(); i++) {
        int u = points[i][0];
        int v = points[i][1];
        q.push(make_pair(dis(u, v), make_pair(u, v)));
    }

    vector<vector<int>> res;
    if (points.size() == 0) return res;

    for(int i = 0; i < K; i++) {
        vector<int> p;
        p.push_back(q.top().second.first);
        p.push_back(q.top().second.second);
        q.pop();
        res.push_back(p);
    }
    return res;
}
