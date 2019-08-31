//
// Created by Hoang, Quang on 2019-08-31.
//

class Solution {
public:
    /*
        fx[i][j] = -oo
        fx[0][1] = a[0]
        fx[i][k] = max(j == 0 ? avg(j, i) : fx[j-1][k-1] + avg(j, i))

        O(n^2 * K)
    */

    int s[1000];

    double avg(int u, int v) {
        if (u == 0) return 1.0 * s[v] / (v-u+1);
        return 1.0 * (s[v] - s[u-1]) / (v-u+1);
    }
    double largestSumOfAverages(vector<int>& a, int K) {
        int n = a.size();
        if (n == 0) return 0;
        double fx[n][K+1];

        s[0] = a[0];
        for(int i = 1; i < n; i++) s[i] = s[i-1] + a[i];

        for(int i = 0; i < n; i++)
            for(int j = 0; j <= K; j++)
                fx[i][j] = INT_MIN;

        fx[0][1] = a[0];

        for(int i = 1; i < n; i++) {
            for(int k = 1; k <= K; k++) {
                for(int j = 0; j <= i; j++) {
                    fx[i][k] = max(fx[i][k], j == 0 ?  avg(j, i) : fx[j - 1][k-1] + avg(j, i));
                }
            }
        }

        return fx[n-1][K];
    }
};