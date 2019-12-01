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
                    if (p[j-1] == '*') 
                        fx[i][j] = fx[i][j] || fx[i][j-2];
                } else {
                    if (p[j-1] == '.' || p[j-1] == s[i-1]) {
                     fx[i][j] = fx[i][j] || fx[i-1][j-1]; // s = ab, p = .b
                    } else {
                        if (p[j-1] == '*') {
                            if (p[j-2] == '.' || p[j-2] == s[i-1]) {
                                fx[i][j] = fx[i][j] || 
                                fx[i][j-2] || // s = aaa, p = a*
                                fx[i-1][j]; // s = ba, p = ba*
                            } else 
                                fx[i][j] = fx[i][j-2];
                        }
                    }    
                }
            }
        
        return fx[n][m];
    }
};