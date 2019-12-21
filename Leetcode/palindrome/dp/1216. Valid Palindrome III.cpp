class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.size();
        int fx[n][n];
        memset(fx, 0, sizeof(fx));

        for (int i = 0; i < n; i++) {
            fx[i][i] = 1;
            if (i < n - 1) {
                if (s[i] == s[i + 1]) fx[i][i + 1] = 2; else fx[i][i + 1] = 1;
            }
        }

        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                fx[i][j] = max(fx[i][j - 1], fx[i + 1][j]);
                if (s[i] == s[j])
                    fx[i][j] = max(fx[i][j], fx[i + 1][j - 1] + 2);
            }
        }

        return n - fx[0][n - 1] <= k;
    }
};