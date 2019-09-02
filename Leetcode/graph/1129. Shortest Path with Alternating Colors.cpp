//
// Created by Hoang, Quang on 2019-09-02.
//

// https://leetcode.com/problems/shortest-path-with-alternating-colors/

class Solution {
public:
    typedef pair<int, int> ii;
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<ii> a[n];
        for(auto e: red_edges) {
            int u = e[0], v = e[1];
            a[u].push_back(ii(v, 1));
        }

        for(auto e: blue_edges) {
            int u = e[0], v = e[1];
            a[u].push_back(ii(v, 0));
        }

        int dis[n][2];
        memset(dis, -1, sizeof(dis));
        dis[0][0] = 0;
        dis[0][1] = 0;
        queue<ii> q;
        q.push(ii(0, 0));
        q.push(ii(0, 1));

        while (!q.empty()) {
            int u = q.front().first;
            int pre_color = q.front().second;
            q.pop();

            for(auto i: a[u]) {
                int v = i.first;
                int color = i.second;
                if (color != pre_color) {
                    if (dis[v][color] == -1) {
                        dis[v][color] = dis[u][pre_color] + 1;
                        q.push(ii(v, color));
                    }
                }
            }
        }
        vector<int> res = vector<int>(n);
        for(int i = 0; i < n; i++) {
            if (dis[i][0] == -1 && dis[i][1] == -1) res[i] = -1;
            else {
                if (dis[i][0] != -1 && dis[i][1] != -1) res[i] = min(dis[i][0], dis[i][1]);
                else res[i] = max(dis[i][0], dis[i][1]);
            }
        }
        return res;
    }
};