//
// Created by Hoang, Quang on 2019-08-10.
//

// https://leetcode.com/problems/number-of-enclaves/

#include <vector>

using namespace std;

class Solution {
public:
    bool visited[501][501];
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    void dfs(int u, int v, vector<vector<int>>& A) {
        visited[u][v] = true;
        int n = A.size();
        int m = A[0].size();

        for(int k = 0; k < 4; k++) {
            int p = u + dx[k];
            int q = v + dy[k];
            if (p >= 0 && p < n)
                if (q >= 0 && q < m)
                    if (A[p][q] == 1 && !visited[p][q]) {
                        dfs(p,q,A);
                    }
        }
    }

    int numEnclaves(vector<vector<int>>& A) {
        memset(visited, 0, sizeof(visited));
        int n = A.size();
        int m = A[0].size();
        int res = 0;

        for(int i = 0; i < n; i++) {
            if (A[i][0]) dfs(i, 0, A);
            if (A[i][m-1]) dfs(i, m-1, A);
        }

        for(int j = 0; j < m; j++) {
            if (A[0][j]) dfs(0, j, A);
            if (A[n-1][j]) dfs(n-1, j, A);
        }


        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)  {
                if (A[i][j] && !visited[i][j]) res++;
            }

        return res;
    }
};
