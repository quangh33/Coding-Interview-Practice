//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:

    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};

    int n, m;
    bool visit[101][101];
    vector <vector<int>> B;

    bool within(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    bool dfs(int u, int v, int mi) {
        visit[u][v] = true;
        if (u == n - 1 && v == m - 1) return true;
        for (int k = 0; k < 4; k++) {
            int i = u + dx[k];
            int j = v + dy[k];
            if (within(i, j) && !visit[i][j] && B[i][j] >= mi) {
                if (dfs(i, j, mi)) return true;
            }
        }
        return false;
    }

    int maximumMinimumPath(vector <vector<int>> &A) {
        n = A.size();
        m = A[0].size();
        B = A;
        int low = 0, high = 1000000000;
        int res = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            memset(visit, false, sizeof(visit));

            if (A[0][0] >= mid && dfs(0, 0, mid)) {
                res = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        return res;
    }
};