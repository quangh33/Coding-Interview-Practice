//
// Created by Hoang, Quang on 2019-08-16.
//

// https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<bool> inDfs;
    vector<int> q;
    int id;
    bool ok;

    void dfs(int u) {
        visited[u] = true;
        inDfs[u] = true;
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (!visited[v]) {
                dfs(v);
            } else if (inDfs[v]) {
                ok = false;
                return;
            }
        }
        q[id--] = u;
        inDfs[u] = false;
    }

    vector<int> findOrder(int n, vector<vector<int>>& e) {
        vector<int> res;
        if (n == 0) return res;
        visited = vector<bool>(n, false);
        inDfs = vector<bool>(n, false);
        adj = vector<vector<int>>(n);

        q = vector<int>(n);
        id = n-1;
        ok = true;

        for(int i = 0; i < e.size(); i++) {
            int u = e[i][0];
            int v = e[i][1];
            adj[v].push_back(u);
        }

        for(int u = 0; u < n; u++)
            if (!visited[u]) {
                dfs(u);
            }

        if (!ok) return res;
        return q;
    }
};