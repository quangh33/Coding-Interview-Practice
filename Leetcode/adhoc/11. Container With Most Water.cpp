//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    int maxArea(vector<int>& a) {
        int res = 0;
        int l = 0, r = a.size() - 1;
        while (l < r) {
            res = max(res, min(a[l], a[r]) * (r-l));
            if (a[l] < a[r]) l++;
            else r--;
        }
        return res;
    }
};