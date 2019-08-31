//
// Created by Hoang, Quang on 2019-08-30.
//

class Solution {
public:
    int p[2000];
    int r[2000];

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

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i = 0; i < 2000; i++) {
            p[i] = i;
            r[i] = 0;
        }

        vector<int> res;

        for(auto e: edges) {
            int u = e[0], v = e[1];
            int u_id = find(u);
            int v_id = find(v);
            if (u_id == v_id) {
                res = { u, v };
            } else merge(u_id, v_id);
        }
        // cout<<res[0]<<" "<<res[1];
        return res;
    }
};