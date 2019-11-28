class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        bool fx[n+1][m+1];
        memset(fx, false, sizeof(fx));
        
        fx[0][0] = 1;
        for(int i = 0; i <= n; i++)
            for(int j = 1; j <= m; j++) {
                if (i == 0) {
                    if (p[j-1] == '*') fx[i][j] = fx[i][j-1];
                } else {
                    if (s[i-1] == p[j-1] || p[j-1] == '?') fx[i][j] |= fx[i-1][j-1];
                    else if (p[j-1] == '*') {
                        fx[i][j] = fx[i][j] || fx[i-1][j] || fx[i][j-1] || fx[i-1][j-1];
                    }
                }
            }
        
        return fx[n][m];
    }
};