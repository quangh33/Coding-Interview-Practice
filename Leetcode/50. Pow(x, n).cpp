//
// Created by Hoang, Quang on 2019-08-05.
//

/*
 * https://leetcode.com/problems/powx-n/
 */

double myPow(double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n == -1) return 1 / x;
    int m = n / 2;
    double y = myPow(x, m);
    if (n % 2 == 0) return y * y;
    if (n > 0) return y * y * x;
    return y * y * (1 / x);
}
