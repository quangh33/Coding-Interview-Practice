//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    int shortestWay(string source, string target) {
        int n = source.size();
        if (n == 0) return -1;
        int prev[n + 1][26];
        memset(prev, -1, sizeof(prev));
        for (int i = 1; i <= n; i++)
            for (char c = 'a'; c <= 'z'; c++) {
                if (source[i - 1] == c) prev[i][c - 'a'] = i - 1;
                else prev[i][c - 'a'] = prev[i - 1][c - 'a'];
            }

        int m = target.size();
        if (m == 0) return 0;
        int fx[m+1];
        fx[0] = 0;
        for (int i = 1; i < m; i++) {
            int cur = n;
            fx[i] = INT_MAX;
            for (int j = i; j >= 0; j--)
                if (fx[j - 1] != INT_MAX) {
                    int c = target[j-1] - 'a';
                    if (prev[cur][c] != -1) {
                        fx[i] = min(fx[i], 1 + fx[j - 1]);
                        cur = prev[cur][c];
                    } else break;
                }
        }
        return fx[m] == INT_MAX ? -1 : fx[m];
    }
};
