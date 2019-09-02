//
// Created by Hoang, Quang on 2019-08-26.
//

// https://leetcode.com/problems/binary-number-with-alternating-bits/

/*
 * n =                  10101010101
 * n >> 1 =             01010101010
 * n ^ (n >> 1) =       11111111111
 * n ^ (n >> 1) + 1 =  100000000000
 */
class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long m = (n ^ (n >> 1L)) + 1L;
        return (m & (m-1)) == 0;
    }
};