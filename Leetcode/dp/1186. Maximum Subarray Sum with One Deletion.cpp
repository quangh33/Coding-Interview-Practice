//
// Created by Hoang, Quang on 2020-01-03.
//

class Solution {
public:
    int maximumSum(vector<int>& a) {
        int n = a.size();
        if (n == 1) return a[0];

        int l[n];
        int r[n];
        l[0] = a[0];
        int res = a[0];

        for(int i = 1; i < n; ++i) {
            l[i] = max(l[i-1] + a[i], a[i]);
            res = max(res, l[i]);
        }

        r[n-1] = a[n-1];
        for(int i = n-2; i >= 0; --i)
            r[i] = max(r[i+1] + a[i], a[i]);

        for(int i = 0; i < n; ++i) {
            if (i == 0) res = max(res, r[i+1]);
            else if (i == n-1) res = max(res, l[n-2]);
            else {
                res = max(res, l[i-1] + max(0, r[i+1]));
                res = max(res, r[i+1] + max(0, l[i-1]));
            }
        }

        return res;
    }
};
