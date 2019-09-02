//
// Created by Hoang, Quang on 2019-09-02.
//

// https://leetcode.com/problems/network-delay-time/

class Solution {
public:
    typedef pair<int, int> ii;

    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<ii> a[N+1];
        for(auto e: times) {
            int u = e[0], v = e[1], w = e[2];
            a[u].push_back(ii(v, w));
        }
        priority_queue<ii, vector<ii>, greater<ii> > q;
        int fx[N+1];
        for(int i = 1; i <= N; i++) fx[i] = INT_MAX;
        fx[K] = 0;
        q.push(ii(0, K));

        while (q.size()) {
            int u = q.top().second;
            q.pop();
            for(auto pair: a[u]) {
                int v = pair.first;
                int w = pair.second;
                if (fx[v] > fx[u] + w) {
                    fx[v] = fx[u] + w;
                    q.push(ii(fx[v], v));
                }
            }
        }

        int res = 0;
        for(int i = 1; i <= N; i++) {
            res = max(res, fx[i]);
        }

        return res == INT_MAX ? -1 : res;
    }
};

