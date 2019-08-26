//
// Created by Hoang, Quang on 2019-08-26.
//

// https://leetcode.com/problems/binary-gap/

class Solution {
public:
    int binaryGap(int n) {
        int last = -1, res = 0;
        for(int i = 0; i < 32; i++)
            if (1 & (n >> i)) {
                if (last > -1)
                    res = max(res, i - last);
                last = i;
            }

        return res;
    }
};

