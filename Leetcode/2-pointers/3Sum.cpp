//
// Created by Hoang, Quang on 2019-09-05.
//

// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> res;

        sort(a.begin(), a.end());

        for(int i = 0; i < n; i++)
            if (i == 0 || (a[i] != a[i-1]))
            {
                int remain = 0 - a[i];
                int l = i + 1, r = n - 1;
                while (l < r) {
                    if (a[l] + a[r] == remain) {
                        res.push_back({ a[i], a[l], a[r] });
                        while (l + 1 < n && a[l+1] == a[l]) l++;
                        while (r - 1 >= 0 && a[r-1] == a[r]) r--;
                        l++;
                        r--;
                    } else if (a[l] + a[r] < remain) l++;
                    else r--;
                }
            }
        return res;
    }
};
