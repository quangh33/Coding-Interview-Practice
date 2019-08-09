//
// Created by Hoang, Quang on 2019-08-09.
//

// https://leetcode.com/problems/find-all-duplicates-in-an-array/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            nums[index] = -nums[index];
            if (nums[index] > 0) res.push_back(index+1);
        }
        return res;
    }
};
