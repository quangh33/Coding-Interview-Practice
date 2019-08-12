//
// Created by Hoang, Quang on 2019-08-12.
//

// https://leetcode.com/problems/shortest-path-in-binary-matrix/

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    bool withinBoundary(int u, int v, int n, int m) {
        return (u >= 0 && u < n && v >= 0 && v < m);
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int dis[n][m];
        queue<pair<int, int>> q;

        q.push(make_pair(0,0));
        memset(dis, -1, sizeof(dis));
        dis[0][0] = 1;

        if (grid[0][0]) return -1;

        while (!q.empty()) {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();

            for(int k = 0; k < 8; k++) {
                int i = u + dx[k];
                int j = v + dy[k];
                if (withinBoundary(i,j,n,m))
                    if (!grid[i][j] && dis[i][j] == -1) {
                        q.push(make_pair(i,j));
                        dis[i][j] = dis[u][v] + 1;

                        if (i == n-1 && j == m-1)
                            return dis[i][j];
                    }
            }
        }
        return dis[n-1][m-1];
    }
};