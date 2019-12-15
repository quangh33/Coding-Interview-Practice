//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};
    bool visit[102][102];
    int n, m;

    bool within(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    bool dfs(int u, int v, vector <vector<int>> &maze, vector<int> &destination) {
        visit[u][v] = true;
        if (destination[0] == u && destination[1] == v) return true;
        for (int k = 0; k < 4; k++) {
            int i = u;
            int j = v;
            while (within(i + dx[k], j + dy[k]) && maze[i + dx[k]][j + dy[k]] == 0) {
                i += dx[k];
                j += dy[k];
            }
            if (!visit[i][j])
                if (dfs(i, j, maze, destination)) return true;
        }
        return false;
    }

    bool hasPath(vector <vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        memset(visit, false, sizeof(visit));
        n = maze.size();
        m = maze[0].size();

        return dfs(start[0], start[1], maze, destination);
    }
};