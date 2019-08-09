//
// Created by Hoang, Quang on 2019-08-09.
//

// https://leetcode.com/problems/two-sum/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            int remain = target - nums[i];
            if (m[remain] != 0 && m[remain] != i+1) {
                res = { i, m[remain] - 1};
                break;
            }
            m[nums[i]] = i+1;
        }
        return res;
    }
};

