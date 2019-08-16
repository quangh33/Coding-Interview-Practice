//
// Created by Hoang, Quang on 2019-08-16.
//

// https://leetcode.com/problems/longest-mountain-in-array/

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        int i = 0;
        int res = 0;
        while (i < n) {
            int j = i;
            while (j+1 < n && A[j+1] > A[j]) j++;
            int k = j;
            while (k + 1 < n && A[k+1] < A[k]) k++;
            if (A[j] > A[i] && A[j] > A[k]) res = max(res, k - i + 1);
            i = j + 1;
        }
        return res;
    }
};
