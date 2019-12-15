//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    vector <vector<int>> a;
    vector<bool> visit;

    void dfs(int u) {
        visit[u] = true;
        for (int v: a[u])
            if (!visit[v]) dfs(v);
    }

    bool validTree(int n, vector <vector<int>> &edges) {
        if (edges.size() >= n) return false;
        a = vector < vector < int >> (n);
        visit = vector<bool>(n, false);

        for (auto e: edges) {
            int u = e[0], v = e[1];
            a[u].push_back(v);
            a[v].push_back(u);
        }

        dfs(0);
        for (int i = 0; i < n; i++)
            if (!visit[i]) return false;
        return true;
    }
};