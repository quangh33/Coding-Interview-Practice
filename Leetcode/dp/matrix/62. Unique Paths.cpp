//
// Created by Hoang, Quang on 2019-08-09.
//

// https://leetcode.com/problems/unique-paths/

#include <cstring>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (n == 0 || m == 0) return 0;
        long long fx[m][n];
        memset(fx, 0, sizeof(fx));
        fx[0][0] = 1;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                if (i-1 >= 0) fx[i][j] += fx[i-1][j];
                if (j-1 >= 0) fx[i][j] += fx[i][j-1];
            }
        return fx[m-1][n-1];
    }
};

