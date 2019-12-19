//
// Created by Hoang, Quang on 2019-12-19.
//

class Solution {
    int n, m;
    int dx[4] = { 0, 1, -1, 0 };
    int dy[4] = { 1, 0, 0, -1 };

    bool within(int u, int v) {
        return (u >= 0 && u < n && v >= 0 && v < m);
    }

    typedef pair<int, int> II;
    typedef pair<II, int> NODE;

public:
    int shortestPath(vector<vector<int>>& a, int k) {
        n = a.size();
        m = a[0].size();

        int fx[41][41][41*41];
        memset(fx, -1, sizeof(fx));

        fx[0][0][k] = 0;
        queue<NODE> q;
        q.push(NODE(II(0, 0), k));

        int res = INT_MAX;

        while (!q.empty()) {
            int u = q.front().first.first;
            int v = q.front().first.second;
            int remain = q.front().second;
            if (u == n-1 && v == m-1)
                res = min(res, fx[u][v][remain]);

            q.pop();

            for(int o = 0; o < 4; o++) {
                int i = u + dx[o];
                int j = v + dy[o];
                if (within(i, j)) {
                    if (a[i][j] == 0) {
                        if (fx[i][j][remain] == -1) {
                            fx[i][j][remain] = fx[u][v][remain] + 1;
                            q.push(NODE(II(i, j), remain));
                        }
                    } else {
                        if (remain > 0 && fx[i][j][remain - 1] == -1) {
                            fx[i][j][remain - 1] = fx[u][v][remain] + 1;
                            q.push(NODE(II(i, j), remain - 1));
                        }
                    }
                }
            }
        }

        if (res == INT_MAX) return -1;
        return res;
    }
};