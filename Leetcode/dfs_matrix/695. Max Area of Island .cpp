//
// Created by Hoang, Quang on 2019-08-10.
//

// https://leetcode.com/problems/max-area-of-island/

#include <vector>
using namespace std;

class Solution {
public:
    bool visited[1000][1000];
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    bool withinBoundary(int u, int v, int n, int m) {
        return (u >= 0 && u < n && v >= 0 && v < m);
    }

    int dfs(int u, int v, vector<vector<int>>& A) {
        visited[u][v] = true;
        int area = 1;

        int n = A.size();
        int m = A[0].size();

        for(int k = 0; k < 4; k++) {
            int p = u + dx[k];
            int q = v + dy[k];
            if (withinBoundary(p, q, n, m))
                if (!visited[p][q] && A[p][q]) {
                    area += dfs(p, q, A);
                }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;

        memset(visited, 0, sizeof(visited));

        int res = 0;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if (!visited[i][j] && grid[i][j]) {
                    res = max(res, dfs(i,j,grid));
                }

        return res;
    }
};

