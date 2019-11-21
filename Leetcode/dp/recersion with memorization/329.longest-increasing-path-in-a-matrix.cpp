class Solution {
public:
    int fx[1000][1000][4];
    int n,m;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    vector<vector<int>> a;

    bool withinBoundary(int i, int j, int n, int m) {
	return (i >= 0 && i < n && j >= 0 && j < m);	    
    }
    int dfs(int u, int v, int d) {
    	if (fx[u][v][d] != -1) return fx[u][v][d];
	int ans = 1;
        for(int k = 0; k < 4; k++)
	if (k + d != 3) {
		int i = u + dx[k];
		int j = v + dy[k];
		if (withinBoundary(i,j,n,m) && a[i][j] > a[u][v]) {
			ans = max(ans, dfs(i, j, k) + 1);
		}
	}		
	fx[u][v][d] = ans;
	return ans;
    }

    int longestIncreasingPath(vector<vector<int>>& b) {
	a = b;
	n = a.size();
	if (n == 0) return 0;
	m = a[0].size();
	if (m == 0) return 0;
	/*
		0
	      1	  2
		3
	*/
	memset(fx, -1, sizeof(fx));
	int res = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			for(int k = 0; k < 4; k++)		
				res = max(res, dfs(i,j,k));
	return res;
    }
};
