//
// Created by Hoang, Quang on 2019-08-25.
//

class Solution {
public:
    bool isSimilar(string s, string t) {
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            count += (s[i] != t[i]);
            if (count > 2) return false;
        }
        return true;
    }

    vector<int> adj[2001];
    vector<bool> visited;

    void dfs(int u) {
        visited[u] = true;
        for(int v: adj[u]) {
            if (!visited[v]) {
                dfs(v);
            }
        }
    }

    int numSimilarGroups(vector<string>& A) {
        int n = A.size();
        if (n == 0) return 0;

        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++)
                if (isSimilar(A[i], A[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
        }
        visited = vector<bool>(n, 0);
        int res = 0;
        for(int i = 0; i < n; i++) {
            if (!visited[i]) {
                res++;
                dfs(i);
            }
        }
        return res;
    }
};