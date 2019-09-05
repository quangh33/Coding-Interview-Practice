//
// Created by Hoang, Quang on 2019-09-03.
//

// https://leetcode.com/problems/minimum-height-trees/

class Solution {
public:
    vector<bool> visit;
    vector<int> dis;
    vector<vector<int>> a;
    vector<int> tr;

    void dfs(int u) {
        visit[u] = true;
        for(int v: a[u])
            if (!visit[v]) {
                dis[v] = dis[u] + 1;
                tr[v] = u;
                dfs(v);
            }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        if (n == 1) {
            res = {0};
            return res;
        }
        a = vector<vector<int>>(n);
        for(auto e: edges) {
            int u = e[0];
            int v = e[1];
            a[u].push_back(v);
            a[v].push_back(u);
        }

        visit = vector<bool>(n, false);
        dis = vector<int>(n, 0);
        tr = vector<int>(n);

        dfs(0);
        int maxDis = 0;
        int u;
        for(int i = 0; i < n; i++)
            if (dis[i] > maxDis) {
                maxDis = dis[i];
                u = i;
            }

        visit = vector<bool>(n, false);
        dis = vector<int>(n, 0);

        dfs(u);

        int v;
        maxDis = 0;
        for(int i = 0; i < n; i++)
            if (dis[i] > maxDis) {
                maxDis = dis[i];
                v = i;
            }

        vector<int> route;
        while (v != u) {
            route.push_back(v);
            v = tr[v];
        }
        route.push_back(u);

        if (maxDis % 2 == 0) {
            res.push_back(route[route.size() / 2]);
        } else {
            res.push_back(route[route.size() / 2 - 1]);
            res.push_back(route[route.size() / 2]);
        }
        return res;
    }
};