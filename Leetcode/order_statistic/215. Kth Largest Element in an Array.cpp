//
// Created by Hoang, Quang on 2019-08-16.
//

// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int partition(vector<int> &nums, int lo, int hi) {
        int pivot = nums[hi];
        int pos = lo;
        for(int i = lo; i < hi; i++) {
            if (nums[i] <= pivot) swap(nums[i], nums[pos++]);
        }
        swap(nums[pos], nums[hi]);
        return pos;
    }

    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int hi = nums.size() - 1;
        int lo = 0;
        while (lo < hi) {
            int i = partition(nums, lo, hi);
            if (i < k) lo = i + 1;
            else if (i > k) hi = i - 1;
            else break;
        }
        return nums[k];
    }
};
