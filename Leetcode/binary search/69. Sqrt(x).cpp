//
// Created by Hoang, Quang on 2019-08-05.
//
/*
 * https://leetcode.com/problems/sqrtx/
 */

int mySqrt(int x) {
    int mi = 0;
    int ma = x;
    double mid;
    int res;
    while (mi <= ma) {
        mid = (mi + ma) / 2;
        if (mid * mid == x) return mid;
        if (mid * mid < x) {
            res = mid;
            mi = mid + 1;
        } else ma = mid - 1;
    }
    return res;
}

