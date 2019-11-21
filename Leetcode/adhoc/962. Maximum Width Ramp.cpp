//
// Created by Hoang, Quang on 2019-09-25.
//

// https://leetcode.com/problems/maximum-width-ramp/

class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        vector<pair<int, int>> b;
        int n = A.size();
        for(int i = 0; i < n; i++)
            b.push_back(make_pair(A[i], i));

        sort(b.begin(), b.end());
        int res = 0;
        int mi = b[0].second;
        for(int i = 1; i < n; i++) {
            res = max(res, b[i].second - mi);
            mi = min(mi, b[i].second);
        }
        return res;
    }
};
