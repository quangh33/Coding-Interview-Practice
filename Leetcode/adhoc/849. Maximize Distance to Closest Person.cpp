//
// Created by Hoang, Quang on 2019-08-28.
//

// https://leetcode.com/problems/maximize-distance-to-closest-person/

class Solution {
public:
    int maxDistToClosest(vector<int>& a) {
        int n = a.size();
        int l[n], r[n];

        l[0] = -1;
        for(int i = 1; i < n; i++) {
            if (a[i-1] == 1) l[i] = i - 1;
            else l[i] = l[i-1];
        }

        r[n-1] = -1;
        for(int i = n-2; i >= 0; i--) {
            if (a[i+1] == 1) r[i] = i + 1;
            else r[i] = r[i+1];
        }

        int res = 0;
        for(int i = 0; i < n; i++)
            if (a[i] == 0)
            {
                int dis = 1e9;
                if (l[i] != -1) dis = i - l[i];
                if (r[i] != -1) dis = min(dis, r[i] - i);
                res = max(res, dis);
            }

        return res;

    }
};