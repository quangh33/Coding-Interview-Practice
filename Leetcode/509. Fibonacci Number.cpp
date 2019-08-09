//
// Created by Hoang, Quang on 2019-08-09.
//

// https://leetcode.com/problems/fibonacci-number/

class Solution {
public:
    int fib(int N) {
        if (N == 0) return 0;
        if (N == 1) return 1;
        int a = 0;
        int b = 1;
        int c;
        for(int i = 2; i <= N; i++) {
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
};