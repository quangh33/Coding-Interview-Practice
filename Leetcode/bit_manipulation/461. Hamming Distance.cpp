//
// Created by Hoang, Quang on 2019-08-26.
//

// https://leetcode.com/problems/hamming-distance/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = (x ^ y);
        int res = 0;
        while (z != 0) {
            res++;
            z &= (z-1);
        }
        return res;
    }
};