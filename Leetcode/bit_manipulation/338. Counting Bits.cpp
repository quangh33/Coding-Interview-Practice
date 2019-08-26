//
// Created by Hoang, Quang on 2019-08-26.
//

// https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        for(int i = 1; i <= num; i++)
            res.push_back(res[(i & (i-1))] + 1);
        return res;
    }
};