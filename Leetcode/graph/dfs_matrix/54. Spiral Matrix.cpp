class Solution {
public:
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };
    
    bool within(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> res;
        if (n == 0) return res;
        int m = a[0].size();
        if (m == 0) return res;
        
        bool used[n][m];
        memset(used, false, sizeof(used));
        int d = 0;
        int count = 1;
        int x = 0, y = 0;
        res.push_back(a[x][y]);
        used[x][y] = true;
        
        while (count < m * n) {
            while (within(x + dx[d], y + dy[d], n, m) && !used[x + dx[d]][y + dy[d]]) {
                x = x + dx[d];
                y = y + dy[d];
                used[x][y] = true;
                res.push_back(a[x][y]);
                count++;
            }
            d = (d + 1) % 4;
        }
        return res;
    }
};