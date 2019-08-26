//
// Created by Hoang, Quang on 2019-08-26.
//

// https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i: nums) res = res xor i;
        return res;
    }
};

