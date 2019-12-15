//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    int BASE = 51;
    int MOD = 1e9 + 7;
    unordered_set<long long> island;
    bool visit[51][51];
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {-1, 0, 0, 1};
    vector<int> path;

    int n, m;

    bool within(int i, int j) {
        return (i < n && j < m && i >= 0 && j >= 0);
    }

    long long hash(vector<int> a) {
        long long hashValue = 0;
        for (int i: a) {
            hashValue = (hashValue * BASE + i) % MOD;
        }
        return hashValue;
    }

    void dfs(int u, int v, vector <vector<int>> grid, int di) {
        visit[u][v] = true;
        path.push_back(di);
        for (int k = 0; k < 4; k++) {
            int i = u + dx[k];
            int j = v + dy[k];
            if (within(i, j) && grid[i][j] == 1 && !visit[i][j]) dfs(i, j, grid, k);
        }
        path.push_back(5);
    }

    int numDistinctIslands(vector <vector<int>> &grid) {
        n = grid.size();
        if (n == 0) return 0;
        m = grid[0].size();
        if (m == 0) return 0;
        memset(visit, false, sizeof(visit));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!visit[i][j] && grid[i][j] == 1) {
                    path = vector<int>();
                    dfs(i, j, grid, 5);
                    long long hashValue = hash(path);
                    island.insert(hashValue);
                }

        return island.size();
    }
};