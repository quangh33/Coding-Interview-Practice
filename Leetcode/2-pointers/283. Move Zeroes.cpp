//
// Created by Hoang, Quang on 2019-08-27.
//

// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int> &a) {
        int n = a.size();
        int boundary = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != 0) swap(a[i], a[boundary++]);
        }
    }
};