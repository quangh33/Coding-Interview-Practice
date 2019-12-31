//
// Created by Hoang, Quang on 2019-08-10.
//

// https://leetcode.com/problems/number-of-islands/
#include <vector>

using namespace std;

class Solution {
public:
    bool visited[1000][1000];
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool withinBoundary(int u, int v, int n, int m) {
        return (u >= 0 && u < n && v >= 0 && v < m);
    }

    void dfs(int u, int v, vector<vector<char>> &A) {
        visited[u][v] = true;

        int n = A.size();
        int m = A[0].size();

        for (int k = 0; k < 4; k++) {
            int p = u + dx[k];
            int q = v + dy[k];
            if (withinBoundary(p, q, n, m))
                if (!visited[p][q] && A[p][q] == '1') {
                    dfs(p, q, A);
                }
        }
    }

    int numIslands(vector<vector<char>> &grid) {
        memset(visited, 0, sizeof(visited));

        int res = 0;
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!visited[i][j] && grid[i][j] == '1') {
                    res++;
                    dfs(i, j, grid);
                }
        return res;
    }
};
