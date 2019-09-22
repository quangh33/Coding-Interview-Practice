//
// Created by Hoang, Quang on 2019-09-06.
//

class Solution {
public:
    vector<int> a[5002];
    int id;
    int q[5002];
    bool visit[5002], inDfs[5002];
    bool can;
    bool b[5002][5002];
    int fx[5002];

    void dfs(int u) {
        visit[u] = true;
        inDfs[u] = true;
        if (!can) return;

        for(int v: a[u]) {
            if (visit[v]) {
                if (inDfs[v]) {
                    can = false;
                    break;
                }
            } else dfs(v);
        }

        q[id--] = u;
        inDfs[u] = false;
    }

    int minimumSemesters(int N, vector<vector<int>>& relations) {
        memset(visit, false, sizeof(visit));
        memset(inDfs, false, sizeof(inDfs));
        memset(b, false, sizeof(b));

        id = N-1;
        for(auto e: relations) {
            int u = e[0];
            int v = e[1];
            a[u].push_back(v);
            b[u][v] = true;
        }
        can = true;
        for(int i = 1; i <= N; i++)
            if (!visit[i]) dfs(i);

        if (!can) return -1;

        fx[0] = 1;
        int res = 1;

        for(int i = 1; i < N; i++) {
            fx[i] = 1;
            for(int j = 0; j < i; j++)
                if (b[q[j]][q[i]]) {
                    fx[i] = max(fx[i], fx[j] + 1);
                }
            res = max(res, fx[i]);
        }

        return res;
    }
};