//
// Created by Hoang, Quang on 2019-08-26.
//

// https://leetcode.com/problems/total-hamming-distance/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int count[32];
        memset(count, 0, sizeof(count));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 32; j++)
                if (1 & (nums[i] >> j)) count[j]++;
        }

        int res = 0;
        for(int i = 0; i < 32; i++)
            res = res + count[i] * (n - count[i]);
        return res;
    }
};