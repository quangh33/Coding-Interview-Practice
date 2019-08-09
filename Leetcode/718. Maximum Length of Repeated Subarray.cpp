//
// Created by Hoang, Quang on 2019-08-09.
//

// https://leetcode.com/problems/maximum-length-of-repeated-subarray/


#include <vector>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        if (n == 0 || m == 0) return 0;
        int fx[n][m];
        for(int i = 0; i < n; i++) fx[i][0] = A[i] == B[0] ? 1 : 0;
        for(int i = 0; i < m; i++) fx[0][i] = A[0] == B[i] ? 1 : 0;
        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++) {
                if (A[i] == B[j]) fx[i][j] = fx[i-1][j-1] + 1;
                else fx[i][j] = 0;
            }

        int res = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) res = max(res, fx[i][j]);

        return res;
    }
};
