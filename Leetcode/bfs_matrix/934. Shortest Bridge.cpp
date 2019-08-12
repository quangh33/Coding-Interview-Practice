//
// Created by Hoang, Quang on 2019-08-10.
//

// https://leetcode.com/problems/shortest-bridge/

#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    bool visited[101][101];
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    bool withinBoundary(int u, int v, int n, int m) {
        return (u >= 0 && u < n && v >= 0 && v < m);
    }
    queue<pair<int, int>> que;
    int dis[101][101];

    void dfs(int u, int v, vector<vector<int>>& A) {
        visited[u][v] = true;
        que.push(make_pair(u, v));
        dis[u][v] = 0;

        int n = A.size();
        int m = A[0].size();

        for(int k = 0; k < 4; k++) {
            int p = u + dx[k];
            int q = v + dy[k];
            if (withinBoundary(p, q, n, m))
                if (!visited[p][q] && A[p][q]) {
                    dfs(p, q, A);
                }
        }
    }
    int shortestBridge(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        que = queue<pair<int, int>>();
        memset(visited, 0, sizeof(visited));
        memset(dis, -1, sizeof(dis));

        bool foundFirstLand = false;
        for(int i = 0; i < n; i++)
        {
            if (foundFirstLand) break;
            for(int j = 0; j < n; j++)
                if (A[i][j]) {
                    foundFirstLand = true;
                    // cout<<i<<" "<<j<<endl;
                    dfs(i, j, A);
                    break;
                }
        }

        while (!que.empty()) {
            int u = que.front().first;
            int v = que.front().second;
            que.pop();

            for(int k = 0; k < 4; k++) {
                int p = u + dx[k];
                int q = v + dy[k];
                if (withinBoundary(p, q, n, m)) {
                    if (dis[p][q] == -1) {
                        dis[p][q] = dis[u][v] + 1;
                        if (A[p][q]) {
                            // cout<<p<<" "<<q;
                            return dis[p][q] - 1;
                        }
                        que.push(make_pair(p, q));
                    }
                }
            }
        }
        return 0;
    }
};