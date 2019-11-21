//
// Created by Hoang, Quang on 2019-11-21.
//

class Solution {
public:
    int p[10002], r[10002];

    int find(int i) {
        if (p[i] == i) return i;
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

    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        for(int i = 1; i <= n; i++) {
            pipes.push_back({ 0, i, wells[i-1] });
        }
        int res = 0;
        for(int i = 0; i <= n; i++) {
            p[i] = i;
            r[i] = 0;
        }

        vector<pair<int, pair<int, int>>> edges;
        for(auto pipe: pipes) {
            edges.push_back(make_pair(pipe[2], make_pair(pipe[0], pipe[1])));
        }
        sort(edges.begin(), edges.end());

        for(auto e: edges) {
            int u = e.second.first;
            int v = e.second.second;
            int rootU = find(u);
            int rootV = find(v);
            if (rootU != rootV) {
                res += e.first;
                merge(rootU, rootV);
            }
        }
        return res;
    }
};