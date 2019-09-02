//
// Created by Hoang, Quang on 2019-09-01.
//

class Solution {
public:
    vector<bool> visit;
    vector<bool> color;

    bool dfs(int i, vector<vector<int>> graph, bool c) {
        visit[i] = true;
        color[i] = c;
        for(int j: graph[i]) {
            if (!visit[j]) {
                if (!dfs(j, graph, !c)) return false;
            } else {
                if (color[i] == color[j]) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        visit = vector<bool>(n, 0);
        color = vector<bool>(n);

        bool res = true;
        for(int i = 0; i < n; i++)
            if (!visit[i]) res = res && dfs(i, graph, 0);
        return res;
    }
};