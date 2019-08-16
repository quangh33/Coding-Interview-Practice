//
// Created by Hoang, Quang on 2019-08-15.
//
// https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int i: nums) {
            count[i]++;
            if (count[i] > 1) return true;
        }
        return false;
    }
};
