class Solution {
public:
    int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    
    int n, m;
    
    bool within(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);    
    }
    
    void gameOfLife(vector<vector<int>>& a) {
        n = a.size();
        if (n == 0) return;
        m = a[0].size();
        if (m == 0) return;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                int live = 0;
                for(int k = 0; k < 8; k++) {
                    int u = i + dx[k];
                    int v = j + dy[k];
                    if (within(u,v) && a[u][v] > 0) {
                        live++;
                    }
                }
                live++;
                if (a[i][j] == 0) a[i][j] = -live;
                else a[i][j] = live;
            }
        
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
            if (a[i][j] > 0) {
                if (a[i][j] < 3) a[i][j] = 0;
                else if (a[i][j] <= 4) a[i][j] = 1;
                else if (a[i][j] > 4) a[i][j] = 0;
            }  else {
                if (abs(a[i][j]) == 4) a[i][j] = 1;
                else a[i][j] = 0;
            } 
        }
    }
};