//
// Created by Hoang, Quang on 2019-08-27.
//
// https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n = a.size();
        reverse(a.begin(), a.end());
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                swap(a[i][j], a[j][i]);
    }
};