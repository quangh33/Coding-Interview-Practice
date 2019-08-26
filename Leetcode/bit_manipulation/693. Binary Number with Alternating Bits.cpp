//
// Created by Hoang, Quang on 2019-08-26.
//

// https://leetcode.com/problems/binary-number-with-alternating-bits/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long m = (n ^ (n >> 1L)) + 1L;
        return (m & (m-1)) == 0;
    }
};