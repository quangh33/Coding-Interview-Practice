//
// Created by Hoang, Quang on 2019-08-10.
//

// https://leetcode.com/problems/island-perimeter/
#include <vector>

using namespace std;

class Solution {
public:
    int dx[4] = { -1, 0, 0, 1 };
    int dy[4] = { 0, 1, -1, 0 };
    bool visited[101][101];
    int perimeter;
    vector<vector<int>> a;

    bool withinBoundary(int u, int v, int n, int m) {
        return (u >= 0 && u < n && v >= 0 && v < m);
    }

    void dfs(int u, int v) {
        visited[u][v] = true;
        int p = 4;
        int n = a.size();
        int m = a[0].size();

        for(int k = 0; k < 4; k++) {
            int x = u + dx[k];
            int y = v + dy[k];
            if (withinBoundary(x,y,n,m) && a[x][y]) {
                p--;
                if (!visited[x][y]) {
                    dfs(x,y);
                }
            }
        }
        perimeter+=p;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n==0) return 0;
        int m = grid[0].size();
        if (m==0) return 0;

        memset(visited, 0, sizeof(visited));
        perimeter = 0;

        a = grid;

        for(int u = 0; u < n; u++)
            for(int v = 0; v < m; v++)
                if (grid[u][v] && !visited[u][v]) {
                    dfs(u,v);
                }

        return perimeter;

    }
};
