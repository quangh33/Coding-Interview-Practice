//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (abs(n - m) > 1) return false;
        if (n > m) return isOneEditDistance(t, s);
        if (n == m) {
            int diff = 0;
            for (int i = 0; i < n; i++)
                if (s[i] != t[i]) diff++;
            return diff == 1;
        } else {
            int i = 0, j = 0;
            int diff = 0;
            while (i < n && j < m) {
                if (s[i] != t[j]) {
                    i--;
                    diff++;
                }
                i++;
                j++;
            }
            return diff <= 1;
        }
    }
};