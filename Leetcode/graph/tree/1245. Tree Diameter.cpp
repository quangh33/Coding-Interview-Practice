//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    vector<int> a[10010];

    vector<int> findFarestNode(int s) {
        queue<int> q;
        int fx[10010];
        q.push(s);
        memset(fx, -1, sizeof(fx));
        fx[s] = 0;
        int ma = 0;
        int res = s;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (fx[u] > ma) {
                ma = fx[u];
                res = u;
            }

            for (int v: a[u]) {
                if (fx[v] == -1) {
                    fx[v] = fx[u] + 1;
                    q.push(v);
                }
            }
        }
        return {res, ma};
    }

    int treeDiameter(vector <vector<int>> &edges) {
        if (edges.size() == 0) return 0;

        for (auto e: edges) {
            int u = e[0];
            int v = e[1];
            a[u].push_back(v);
            a[v].push_back(u);
        }

        vector<int> x = findFarestNode(0);
        int t = x[0];
        vector<int> y = findFarestNode(t);
        return y[1];
    }
};