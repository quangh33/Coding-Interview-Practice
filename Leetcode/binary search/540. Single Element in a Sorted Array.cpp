//
// Created by Hoang, Quang on 2019-09-02.
//

// https://leetcode.com/problems/single-element-in-a-sorted-array/
/*
 * ...abbcc
 * ...aacbb
 */
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (mid % 2 == 1) mid--;
            if (nums[mid] != nums[mid+1]) high = mid;
            else low = mid + 2;
        }
        return nums[low];
    }
};