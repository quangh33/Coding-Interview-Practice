//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int n = s.size();
        if (n == 0) return 0;
        int fx[n];
        memset(fx, 0, sizeof(fx));
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(')
                    fx[i] = i - 2 >= 0 ? fx[i - 2] + 2 : 2;
                else {
                    if (i - fx[i - 1] - 1 >= 0 && s[i - fx[i - 1] - 1] == '(')
                        fx[i] = fx[i - 1] + 2 + (i - fx[i - 1] - 2 >= 0 ? fx[i - fx[i - 1] - 2] : 0);
                }
            }
            res = max(res, fx[i]);
        }
        return res;
    }
};