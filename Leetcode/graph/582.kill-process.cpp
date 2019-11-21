class Solution {
public:
    unordered_map<int ,vector<int>> a;
    vector<int> res;

    void dfs(int u) {
	res.push_back(u);
	if (a.count(u) != 0)
		for(int v: a[u]) dfs(v);
    } 

    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
	int n = pid.size();
	for(int i = 0; i < n; i++) {
		int u = pid[i];
		int p = ppid[i];
		a[p].push_back(u);
	}        
	dfs(kill);
	return res;
    }
};
