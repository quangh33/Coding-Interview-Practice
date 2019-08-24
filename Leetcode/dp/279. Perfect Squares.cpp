//
// Created by Hoang, Quang on 2019-08-23.
//

class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) return 0;
        vector<int> fx(n+1, INT_MAX);
        fx[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j * j <= i; j++) {
                fx[i] = min(fx[i], fx[i - j*j] + 1);
            }
        }
        return fx[n];
    }
};
