//
// Created by Hoang, Quang on 2019-09-04.
//

// https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int n = a.size();
        if (n == 0) return 0;
        int m = a[0].size();
        if (m == 0) return 0;
        int row = n - 1;
        int col = 0;
        while (row >= 0 && col < m) {
            if (a[row][col] > target) row--;
            else if (a[row][col] < target) col++;
            else return true;
        }
        return false;
    }
};