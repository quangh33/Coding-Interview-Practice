//
// Created by Hoang, Quang on 2019-09-05.
//

class Solution {
public:
    int p[10001];
    int r[10001];

    int find(int i) {
        if (i == p[i]) return i;
        return (find(p[i]));
    }

    void merge(int i, int j) {
        if (r[i] > r[j]) {
            p[j] = i;
        } else {
            p[i] = j;
            if (r[i] == r[j]) r[j]++;
        }
    }

    int minimumCost(int n, vector<vector<int>>& connections) {
        vector<pair<int, pair<int, int>>> a;
        for(auto e: connections) {
            int w = e[2];
            int u = e[0];
            int v = e[1];
            a.push_back(make_pair(w, make_pair(u, v)));
        }
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++) {
            p[i] = i;
            r[i] = 0;
        }

        int res = 0;
        int count = 0;
        for(int i = 0; i < a.size(); i++) {
            int u = a[i].second.first;
            int v = a[i].second.second;
            int uRoot = find(u);
            int vRoot = find(v);
            if (uRoot != vRoot) {
                res += a[i].first;
                count++;
                merge(uRoot, vRoot);
            }
        }
        return count == n-1 ? res : -1;
    }
};