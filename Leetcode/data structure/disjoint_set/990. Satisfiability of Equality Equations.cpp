//
// Created by Hoang, Quang on 2019-08-31.
//

class Solution {
public:
    int p[100];
    int r[100];

    int find(int u) {
        if (u == p[u]) return u;
        return find(p[u]);
    }

    void merge(int u, int v) {
        if (r[u] > r[v]) {
            p[v] = u;
        } else {
            p[u] = v;
            if (r[u] == r[v]) r[v]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();


        for(int i = 0; i < 26; i++) {
            p[i] = i;
            r[i] = 0;
        }

        for(string s: equations) {
            if (s[1] == '=') {
                int u = s[0] - 'a';
                int v = s[3] - 'a';
                int root_u = find(u);
                int root_v = find(v);
                if (root_u != root_v) merge(root_u, root_v);
            }
        }

        for(string s: equations) {
            if (s[1] == '!') {
                int u = s[0] - 'a';
                int v = s[3] - 'a';
                int root_u = find(u);
                int root_v = find(v);
                if (root_u == root_v) return false;
            }
        }
        return true;
    }
};