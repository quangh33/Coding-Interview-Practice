//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    // http://flashing-thoughts.blogspot.com/2010/06/everything-about-bottleneck-spanning.html

    int p[200];
    int r[200];

    typedef pair<int, int> ii;

    int find(int i) {
        if (i == p[i]) return i;
        return find(p[i]);
    }

    void merge(int i, int j) {
        if (r[i] > r[j]) {
            p[j] = i;
        } else {
            p[i] = j;
            if (r[i] == r[j]) r[j]++;
        }
    }


    int earliestAcq(vector <vector<int>> &logs, int N) {
        vector <pair<int, ii>> e;
        for (auto log: logs) {
            e.push_back(make_pair(log[0], ii(log[1], log[2])));
        }

        for (int i = 0; i < N; i++) {
            p[i] = i;
            r[i] = 0;
        }

        sort(e.begin(), e.end());
        int res = 0;
        for (auto edge: e) {
            int u = edge.second.first;
            int v = edge.second.second;
            int w = edge.first;
            int rootU = find(u);
            int rootV = find(v);
            if (rootU != rootV) {
                res = max(res, w);
                merge(rootU, rootV);
            }
        }

        int root = find(0);
        bool ok = true;
        for (int i = 1; i < N; i++)
            if (find(i) != root) ok = false;

        if (!ok) return -1;
        return res;
    }
};