//
// Created by Hoang, Quang on 2019-08-10.
//

// https://leetcode.com/problems/friend-circles/

#include <vector>
using namespace std;

class Solution {
public:
    bool visited[201];

    void dfs(int u, vector<vector<int>>& M) {
        visited[u] = true;
        for(int v = 0; v < M.size(); v++) {
            if (!visited[v] && M[u][v]) dfs(v, M);
        }
    }

    int findCircleNum(vector<vector<int>>& M) {
        memset(visited, 0, sizeof(visited));
        int res = 0;
        for(int u = 0; u < M.size(); u++)
            if (!visited[u]) {
                res++;
                dfs(u, M);
            }
        return res;
    }
};

