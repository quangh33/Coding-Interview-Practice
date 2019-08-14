//
// Created by Hoang, Quang on 2019-08-14.
//

// https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int fx[n];
        fx[0] = nums[0];
        fx[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++)
            fx[i] = max(fx[i-1], fx[i-2] + nums[i]);

        return fx[n-1];
    }
};