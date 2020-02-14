class Solution {
    vector<int> a[10010];
    int sum[10010];
    vector<int> value;
    int res = 0;

    int dfs(int u) {
        sum[u] = value[u];
        for(int v: a[u])
            sum[u] += dfs(v);
        return sum[u];
    }

    void count(int u) {
        if (sum[u] == 0) return;
        res++;
        for(int v: a[u])
            count(v);
    }

public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        int n = parent.size();
        this->value = value;

        for(int i = 0; i < n; i++) {
            if (i != 0)
                a[parent[i]].push_back(i);
        }

        dfs(0);
        count(0);
        return res;
    }
};