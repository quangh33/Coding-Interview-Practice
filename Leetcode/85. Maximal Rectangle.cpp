//
// Created by Hoang, Quang on 2019-08-12.
//

// https://leetcode.com/problems/maximal-rectangle/

#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& a) {
        int n = a.size();
        if (n == 0) return 0;
        int m = a[0].size();
        if (m == 0) return 0;

        int l[m], r[m];

        int h[n][m];
        int res = 0;


        for(int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '0') h[i][j] = 0;
                else {
                    if (i == 0) h[i][j] = 1; else h[i][j] = h[i-1][j] + 1;
                }
            }

            l[0] = -1;
            r[m-1] = m;

            for(int j = 1; j < m; j++) {
                if (h[i][j-1] < h[i][j]) l[j] = j-1;
                else {
                    int k = j-1;
                    while (k != -1 && h[i][k] >= h[i][j]) k = l[k];
                    l[j] = k;
                }
            }

            for(int j = m-2 ; j >= 0; j--) {
                if (h[i][j+1] < h[i][j]) r[j] = j+1;
                else {
                    int k = j+1;
                    while (k != m && h[i][k] >= h[i][j]) k = r[k];
                    r[j] = k;
                }
            }

            for (int j = 0; j < m; j++)
            {
                res = max(res, h[i][j] * (r[j] - l[j] - 1));
            }

        }
        return res;
    }
};