//
// Created by Hoang, Quang on 2019-08-14.
//

// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& a, int k) {
        int n = a.size();
        int m = a[0].size();
        int ans = INT_MIN;

        int s[n][m];

        for(int i = 0; i < n; i++) s[i][0] = a[i][0];
        for(int j = 1; j < m; j++)
            for(int i = 0; i < n; i++) s[i][j] = s[i][j-1] + a[i][j];

        for(int l = 0; l < m; l++)
            for(int r = l; r < m; r++) {
                int b[n];
                for(int i = 0; i < n; i++) b[i] = l == 0 ? s[i][r] : s[i][r] - s[i][l-1];

                set<int> s;
                s.insert(0);
                int cum = 0;
                for(int i = 0; i < n; i++) {
                    cum += b[i];
                    set<int>::iterator it = s.lower_bound(cum-k);
                    if (it != s.end()) ans = max(ans, cum - *it);
                    s.insert(cum);
                }
            }

        return ans;
    }
};

