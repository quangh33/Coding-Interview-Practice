//
// Created by Hoang, Quang on 2019-08-05.
//

/*
 * https://leetcode.com/problems/valid-perfect-square/
 */

bool isPerfectSquare(int num) {
    int mi = 0;
    int ma = num;
    double mid;
    while (mi <= ma) {
        mid = (mi + ma) / 2;
        double sqr = mid * mid;
        if (sqr == num) return true;
        if (sqr < num) mi = mid + 1;
        else ma = mid - 1;
    }
    return false;
}


