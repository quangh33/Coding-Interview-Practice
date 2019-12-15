//
// Created by Hoang, Quang on 2019-08-31.
//

class Solution {
public:
    const static int MAX_N = 30 * 30 * 4 + 10;
    int p[MAX_N];
    int r[MAX_N];

    int find(int i) {
        if (i == p[i]) return i;
        return find(p[i]);
    }

    void merge(int i, int j) {
        int u = find(i);
        int v = find(j);
        if (u != v) {
            if (r[u] > r[v]) {
                p[v] = u;
            } else {
                p[u] = v;
                if (r[u] == r[v]) r[v]++;
            }
        }
    }

    int regionsBySlashes(vector<string>& a) {
        int n = a.size();
        for(int i = 0; i < n * n * 4; i++) {
            p[i] = i;
            r[i] = 0;
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                int u = 4 * (i * n + j);
                if (a[i][j] != '/') {
                    merge(u, u + 1);
                    merge(u + 2, u + 3);
                }

                if (a[i][j] != '\\') {
                    merge(u, u + 3);
                    merge(u + 1, u + 2);
                }

                if (i + 1 < n) {
                    merge(u + 2, 4 * ((i + 1) * n + j));
                }

                if (i - 1 >= 0) {
                    merge(u, 4 * ((i-1) * n + j) + 2);
                }

                if (j + 1 < n) {
                    merge(u + 1, 4 * (i * n + j + 1) + 3);
                }

                if (j - 1 >= 0) {
                    merge(u + 3, 4 * (i * n + j - 1) + 1);
                }
            }

        int res = 0;
        for(int i = 0; i < n * n * 4; i++)
            if (p[i] == i) res++;

        return res;
    }
};