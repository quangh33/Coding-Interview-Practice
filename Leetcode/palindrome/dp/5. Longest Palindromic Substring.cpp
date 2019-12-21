class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";
        
        int u = 0, v = 0;
        int maxLen = 1;
        
        bool fx[n][n];
        memset(fx, false, sizeof(fx));
        
        for(int i = 0; i < n; i++) {
            fx[i][i] = 1;
            if (i < n-1 && s[i] == s[i+1]){
                fx[i][i+1] = 1;
                maxLen = 2;
                u = i;
                v = i + 1;
            }
        }
        
        for(int len = 3; len <= n; len++) {
            for(int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                fx[i][j] = s[i] == s[j] ? fx[i+1][j-1] : 0;
                if (fx[i][j]) {
                    maxLen = len;
                    u = i;
                    v = j;
                }
            }
        }
        
        return s.substr(u, v-u+1);
    }
};