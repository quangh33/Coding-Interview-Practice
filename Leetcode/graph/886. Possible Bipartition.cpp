//
// Created by Hoang, Quang on 2019-09-01.
//

// https://leetcode.com/problems/possible-bipartition/

class Solution {
public:
    vector<int> a[2001];
    vector<bool> visit;
    vector<bool> color;

    bool dfs(int u, bool c) {
        visit[u] = true;
        color[u] = c;
        for(int v: a[u]) {
            if (!visit[v]) {
                if (!dfs(v, !c)) return false;
            } else {
                if (color[u] == color[v]) return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for(auto dislike: dislikes) {
            int u = dislike[0];
            int v = dislike[1];
            a[u].push_back(v);
            a[v].push_back(u);
        }
        visit = vector<bool>(n+1, false);
        color = vector<bool>(n+1);
        bool can = true;

        for(int i = 1; i <= n; i++)
            if (!visit[i]) {
                can = can && dfs(i, 0);
            }

        return can;
    }
};