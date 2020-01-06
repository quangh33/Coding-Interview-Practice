//
// Created by Hoang, Quang on 2020-01-06.
//

class Solution {
    unordered_map<string, int> id;
    string name[10040];
    vector<int> a[10040];
    vector<int> pa;
    vector<bool> visited;
    int n = -1;

    int getId(string s) {
        if (id.find(s) == id.end()) {
            n++;
            id[s] = n;
            name[n] = s;
            return n;
        }
        return id[s];
    }

    void dfs(int u) {
        visited[u] = true;
        for (int v: a[u])
            if (!visited[v]) {
                pa[v] = u;
                dfs(v);
            }
    }

public:
    string findSmallestRegion(vector <vector<string>> &regions, string region1, string region2) {
        for (auto region: regions) {
            int u, v;
            for (int i = 0; i < region.size(); i++) {
                if (i == 0) {
                    u = getId(region[i]);
                } else {
                    v = getId(region[i]);
                    a[u].push_back(v);
                }
            }
        }
        n++;
        visited = vector<bool>(n, false);
        pa = vector<int>(n, -1);
        for (int i = 0; i < n; i++)
            if (!visited[i]) dfs(i);

        int u = getId(region1);
        int v = getId(region2);

        unordered_set<int> ancestors;
        if (region1 == region2) return region1;

        while (u != -1) {
            ancestors.insert(u);
            u = pa[u];
        }

        while (ancestors.count(v) == 0) {
            v = pa[v];
        }

        return name[v];
    }
};