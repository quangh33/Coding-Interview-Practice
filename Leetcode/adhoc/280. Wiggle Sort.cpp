//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        bool less = true;
        if (nums.size() == 0) return;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (less) {
                if (nums[i] > nums[i + 1]) swap(nums[i], nums[i + 1]);
            } else {
                if (nums[i] < nums[i + 1]) swap(nums[i], nums[i + 1]);
            }
            less = !less;
        }
    }
};