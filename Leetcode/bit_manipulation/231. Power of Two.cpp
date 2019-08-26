//
// Created by Hoang, Quang on 2019-08-26.
//

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && (!(n & (n-1)));
    }
};