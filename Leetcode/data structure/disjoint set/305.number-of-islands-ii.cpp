class Solution {
public:
    vector<int> p;
    vector<int> r;
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};

    int find(int u) {
        if (u == p[u]) return u;
        return find(p[u]);
    }

    void merge(int i, int j) {
        if (r[i] > r[j]) {
            p[j] = i;
        } else {
            p[i] = j;
            if (r[i] == r[j]) r[j]++;
        }
    }

    int transform(int i, int j, int m) {
        return i * m + j;
    }

    bool withinBoundary(int i, int j, int m, int n) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

    vector<int> numIslands2(int m, int n, vector <vector<int>> &positions) {
        p = vector<int>(m * n);
        r = vector<int>(m * n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                int ind = transform(i, j, n);
                p[ind] = ind;
                r[ind] = 0;
            }
        vector<int> res;

        int a[m][n];
        memset(a, 0, sizeof(a));
        unordered_set<int> pos;

        for (int ii = 0; ii < positions.size(); ii++) {
            int u = positions[ii][0], v = positions[ii][1];
            if (a[u][v] == 1) {
                res.push_back(res[res.size() - 1]);
                continue;
            }
            a[u][v] = 1;
            pos.insert(transform(u, v, n));
            for (int k = 0; k < 4; k++) {
                int i = u + dx[k];
                int j = v + dy[k];
                if (withinBoundary(i, j, m, n) && a[i][j] == 1) {
                    int rootIJ = find(transform(i, j, n));
                    int rootUV = find(transform(u, v, n));
                    if (rootIJ != rootUV) {
                        merge(rootIJ, rootUV);
                    }
                }
            }
            int count = 0;
            for (auto ind: pos) {
                if (ind == p[ind]) count++;
            }
            res.push_back(count);
        }
        return res;
    }
};
