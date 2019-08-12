//
// Created by Hoang, Quang on 2019-08-12.
//

// https://leetcode.com/problems/01-matrix/

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, 1, -1, 0};

    bool withinBoundary(int u, int v, int n, int m) {
        return (u < n && u >= 0 && v < m && v >= 0);
    }

    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dis;
        for (int i = 0; i < n; i++)
            dis.push_back(vector<int>(m, -1));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (matrix[i][j] == 0) {
                    dis[i][j] = 0;
                    q.push(make_pair(i, j));
                }

        while (!q.empty()) {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int i = u + dx[k];
                int j = v + dy[k];
                if (withinBoundary(i, j, n, m))
                    if (dis[i][j] == -1) {
                        dis[i][j] = dis[u][v] + 1;
                        q.push(make_pair(i, j));
                    }
            }
        }
        return dis;
    }
};

