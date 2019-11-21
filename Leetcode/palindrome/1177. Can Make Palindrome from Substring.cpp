//
// Created by Hoang, Quang on 2019-11-21.
//

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int count[n][26];
        memset(count, 0, sizeof(count));
        count[0][s[0] - 'a'] = 1;
        for(int i = 1; i < n; i++)
            for(char c = 'a'; c <= 'z'; c++) {
                count[i][c-'a'] = count[i-1][c-'a'];
                if (c == s[i]) count[i][c-'a']++;
            }

        vector<bool> res;
        for(auto q: queries) {
            int u = q[0];
            int v = q[1];
            int k = q[2];
            int b[26];
            for(int i = 0; i < 26; i++)
                b[i] = count[v][i] - (u == 0 ? 0 : count[u-1][i]);

            int even = 0;
            for(int i = 0; i < 26; i++)
                if (b[i] % 2 == 0) even += b[i];
                else even += (b[i] - 1);

            if ((v - u + 1) % 2 == 0) {
                if (v-u+1-even <= k * 2) res.push_back(true);
                else res.push_back(false);
            } else {
                if (v-u+1-even-1 <= k * 2)  res.push_back(true);
                else res.push_back(false);
            }
        }

        return res;
    }
};
