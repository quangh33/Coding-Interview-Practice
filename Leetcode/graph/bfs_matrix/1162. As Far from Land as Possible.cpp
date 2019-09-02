//
// Created by Hoang, Quang on 2019-09-02.
//

// https://leetcode.com/problems/as-far-from-land-as-possible/

class Solution {
public:
    typedef pair<int, int> ii;

    int dx[4] = { 0, 1, -1, 0 };
    int dy[4] = { 1, 0, 0, -1 };

    bool withinBoundary(int i, int j, int n, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    int maxDistance(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        int dis[n][m];

        queue<ii> q;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if (a[i][j] == 1) {
                    dis[i][j] = 0;
                    q.push(ii(i, j));
                } else dis[i][j] = -1;

        while (!q.empty()) {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++) {
                int i = u + dx[k];
                int j = v + dy[k];
                if (withinBoundary(i,j,n,m) && dis[i][j] == -1) {
                    dis[i][j] = dis[u][v] + 1;
                    q.push(ii(i, j));
                }
            }
        }

        int res = -1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if (a[i][j] == 0) {
                    res = max(res, dis[i][j]);
                }

        return res;
    }
};