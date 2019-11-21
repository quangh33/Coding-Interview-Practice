class Solution {
public:
    vector<vector<int>> a;
    vector<bool> visit;

    void dfs(int u) {
	visit[u] = true;
	for(int v: a[u]) 
		if (!visit[v]) dfs(v);
    }

    int countComponents(int n, vector<vector<int>>& edges) {
	if (n == 0) return 0;
        a = vector<vector<int>>(n);
	for(auto e: edges) {
		int u = e[0], v = e[1];
		a[u].push_back(v);
		a[v].push_back(u);
	}
	visit = vector<bool>(n, 0);
	int res = 0;
	for(int i = 0; i < n; i++)
		if (!visit[i]) {
			res++;
			dfs(i);
		}
	return res;
    }
};
