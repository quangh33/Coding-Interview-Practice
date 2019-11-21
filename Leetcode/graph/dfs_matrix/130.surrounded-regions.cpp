class Solution {
public:
    int n, m;
    bool within(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }
    int dx[4] = { 1, 0, 0, -1 };
    int dy[4] = { 0, -1, 1, 0 };
    vector<vector<char>> a;
    vector<vector<bool>> visit;
    vector<vector<int>> candidate;
    bool capture;

    void dfs(int u, int v) {
        if (u == 0 || u == n-1 || v == 0 || v == m-1) capture = false;
    	visit[u][v] = true;
	candidate.push_back({ u, v });
	for(int k = 0; k < 4; k++) {
		int i = u + dx[k];
		int j = v + dy[k];
		if (within(i,j) && a[i][j] == 'O' && !visit[i][j]) {
			dfs(i, j);
		}
	}    	
    }
    void solve(vector<vector<char>>& board) {
	a = board;
	n = a.size();
	if (n == 0) return;
	m = a[0].size();
	if (m == 0) return;
	visit = vector<vector<bool>>(n, vector<bool>(m, false));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) 
			if (a[i][j] == 'O' && !visit[i][j]) {
				capture = true;
				candidate.clear();
				dfs(i, j);
				if (capture) 
					for(auto c: candidate)
						board[c[0]][c[1]] = 'X';
			}
    }
};
