//
// Created by Hoang, Quang on 2019-08-27.
//

// https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {
public:
    vector<int> sortedSquares(vector<int> &a) {
        int n = a.size();
        int i;
        for (i = 0; i < n; i++) {
            if (a[i] >= 0) break;
        }
        vector<int> res;
        int j = i - 1;
        while (i < n && j >= 0) {
            if (a[i] * a[i] < a[j] * a[j]) {
                res.push_back(a[i] * a[i]);
                i++;
            } else {
                res.push_back(a[j] * a[j]);
                j--;
            }
        }
        for (int k = i; k < n; k++) res.push_back(a[k] * a[k]);
        for (int k = j; k >= 0; k--) res.push_back(a[k] * a[k]);
        return res;
    }
};
