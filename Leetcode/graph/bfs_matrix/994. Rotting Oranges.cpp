//
// Created by Hoang, Quang on 2019-08-12.
//

// https://leetcode.com/problems/rotting-oranges/

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int dx[4] = { 1, 0, 0, -1 };
    int dy[4] = { 0, 1, -1, 0 };

    bool withinBoundary(int u, int v, int n, int m) {
        return (u >= 0 && u < n && v >=0 && v <m);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int dis[11][11];
        memset(dis, -1, sizeof(dis));

        int fresh = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                if (grid[i][j] == 1) fresh++;
                if (grid[i][j] == 2) {
                    dis[i][j] = 0;
                    q.push(make_pair(i,j));
                }
            }

        if (fresh == 0) return 0;

        int res = 0;
        int freshCanBeRotten = 0;

        while (!q.empty()) {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++) {
                int i = u + dx[k];
                int j = v + dy[k];
                if (withinBoundary(i,j,n,m))
                    if (dis[i][j] == -1 && grid[i][j] == 1) {
                        freshCanBeRotten++;
                        dis[i][j] = dis[u][v]+1;
                        res = max(res, dis[i][j]);
                        q.push(make_pair(i,j));
                    }
            }
        }

        if (freshCanBeRotten < fresh) return -1;
        return res;
    }
};
