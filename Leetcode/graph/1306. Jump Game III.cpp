//
// Created by Hoang, Quang on 2019-12-31.
//

class Solution {
public:
    vector<bool> visited;
    bool res = false;

    void dfs(int u, vector<int> a) {
        visited[u] = true;
        if (a[u] == 0) res = true;

        int v = u - a[u];
        if (v >= 0 && !visited[v])
            dfs(v, a);

        v = u + a[u];
        if (v < a.size() && !visited[v])
            dfs(v, a);
    }

    bool canReach(vector<int>& a, int start) {
        int n = a.size();
        visited = vector<bool>(n, false);
        dfs(start, a);
        return res;
    }
};
