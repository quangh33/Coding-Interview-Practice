//
// Created by Hoang, Quang on 2019-08-15.
//

// https://leetcode.com/problems/range-sum-query-immutable/

class NumArray {
public:
    vector<int> s;

    NumArray(vector<int> &nums) {
        s = vector<int>(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) s[0] = nums[0];
            else s[i] = s[i - 1] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) return s[j];
        return s[j] - s[i - 1];
    }
};

