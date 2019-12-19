//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    typedef pair<int, int> ii;

    int n, m;

    bool within(int i, int j) {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }

    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};

    int shortestDistance(vector <vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        n = maze.size();
        m = maze[0].size();
        queue <pair<int, int>> q;
        q.push(ii(start[0], start[1]));
        int fx[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) fx[i][j] = INT_MAX;

        fx[start[0]][start[1]] = 0;

        while (!q.empty()) {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int i = u;
                int j = v;
                int dis = 0;
                while (within(i + dx[k], j + dy[k]) && maze[i + dx[k]][j + dy[k]] == 0) {
                    i += dx[k];
                    j += dy[k];
                    dis++;
                }
                if (fx[i][j] > fx[u][v] + dis) {
                    fx[i][j] = fx[u][v] + dis;
                    q.push(ii(i, j));
                };
            }
        }

        return fx[destination[0]][destination[1]] != INT_MAX ? fx[destination[0]][destination[1]] : -1;
    }
};