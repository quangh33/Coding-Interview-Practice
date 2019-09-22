//
// Created by Hoang, Quang on 2019-09-05.
//

// https://leetcode.com/problems/subarray-product-less-than-k/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        int n = a.size();
        int res = 0;
        if (n == 0) return 0;

        int i = 0, j = 0;
        long long p = a[0];
        while (i < n) {
            if (p < k || p == 1) {
                if (p < k) res = res + (i - j + 1);
                i++;
                if (i < n) p *= a[i];
            } else {
                p = p / a[j];
                j++;
            }
        }
        return res;
    }
};