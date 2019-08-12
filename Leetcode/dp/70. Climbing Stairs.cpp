//
// Created by Hoang, Quang on 2019-08-09.
//

// https://leetcode.com/problems/climbing-stairs/

#include <cstring>

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        int fx[n+1];
        memset(fx, 0, sizeof(fx));
        fx[0] = 1;
        for(int i = 1; i <= n; i++) {
            fx[i]+=fx[i-1];
            if (i-2 >= 0) fx[i]+=fx[i-2];
        }
        return fx[n];
    }
};