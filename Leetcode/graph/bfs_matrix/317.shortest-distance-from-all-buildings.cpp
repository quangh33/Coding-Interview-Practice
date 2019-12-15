class Solution {
public:
    int n, m, numBuilding, res;
    vector <vector<int>> dis;
    vector <vector<int>> count;
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};
    vector <vector<int>> a;

    bool within(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; };
    typedef pair<int, int> ii;

    void bfs(int x, int y) {
        int visit[n][m];
        memset(visit, -1, sizeof(visit));
        queue <ii> q;
        q.push(ii(x, y));
        visit[x][y] = 0;
        while (!q.empty()) {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int i = u + dx[k];
                int j = v + dy[k];
                if (within(i, j) && visit[i][j] == -1 && a[i][j] == 0) {
                    visit[i][j] = visit[u][v] + 1;
                    dis[i][j] += visit[i][j];
                    count[i][j]++;
                    q.push(ii(i, j));
                }
            }
        }
    }

    int shortestDistance(vector <vector<int>> &grid) {
        n = grid.size();
        if (n == 0) return 0;
        m = grid[0].size();
        if (m == 0) return 0;
        a = grid;
        dis = vector < vector < int >> (n, vector<int>(m, 0));
        count = vector < vector < int >> (n, vector<int>(m, 0));
        numBuilding = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) {
                    numBuilding++;
                    bfs(i, j);
                }
            }

        int res = INT_MAX;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0 && count[i][j] == numBuilding)
                    res = min(res, dis[i][j]);
            }

        return res == INT_MAX ? -1 : res;
    }
};
