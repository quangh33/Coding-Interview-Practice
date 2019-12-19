//
// Created by Hoang, Quang on 2019-08-05.
//

/*
 * https://leetcode.com/problems/powx-n/
 */

class Solution {
public:
    double pow(double x, long long n) {
        if (n < 0) return 1.0 / pow(x, -n);
        if (n == 0) return 1;
        if (n == 1) return x;
        double y = pow(x, n / 2);
        if (n % 2 == 0) return y * y;
        return y * y * x;
    }

    double myPow(double x, int n) {
        return pow(x, n);
    }
};
