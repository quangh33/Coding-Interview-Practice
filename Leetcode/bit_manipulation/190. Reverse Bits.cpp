//
// Created by Hoang, Quang on 2019-08-26.
//

class Solution {
public:
    void swap(uint32_t &n, int i, int j) {
        if ((1 & (n >> i)) != (1 & (n >> j))) {
            uint mask = (1 << i) | (1 << j);
            n ^= mask;
        }
    }

    uint32_t reverseBits(uint32_t n) {
        for(int i = 0; i < 16; i++)
            swap(n, i, 31 - i);
        return n;
    }

};