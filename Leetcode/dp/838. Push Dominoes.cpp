//
// Created by Hoang, Quang on 2019-09-05.
//

// https://leetcode.com/problems/push-dominoes/

class Solution {
public:
    string pushDominoes(string a) {
        int n = a.size();
        if (n == 0) return "";
        int l[n], r[n];
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));

        r[0] = a[0] == 'R' ? 0 : INT_MAX;
        for(int i = 1; i < n; i++) {
            if (a[i] == 'L') r[i] = INT_MAX;
            else if (a[i] == 'R') r[i] = 0;
            else {
                if (r[i-1] == INT_MAX) r[i] = INT_MAX; else r[i] = r[i-1] + 1;
            }
        }

        l[n-1] = a[n-1] == 'L' ? 0 : INT_MAX;
        for(int i = n-2; i >= 0; i--) {
            if (a[i] == 'R') l[i] = INT_MAX;
            else if (a[i] == 'L') l[i] = 0;
            else {
                if (l[i+1] == INT_MAX) l[i] = INT_MAX; else l[i] = l[i+1] + 1;
            }
        }
        string res = "";
        for(int i = 0; i < n; i++) {
            if (l[i] == r[i]) res += '.';
            else {
                if (l[i] < r[i]) res += 'L';
                else res += 'R';
            }
        }
        return res;
    }
};
