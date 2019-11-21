//
// Created by Hoang, Quang on 2019-09-24.
//

// https://leetcode.com/problems/Next-Greater-Element-II/description/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        vector<int> res;
        if (a.size() == 0) return res;
        vector<int> nums = a;
        for(int i = 0; i < a.size() - 1; i++) nums.push_back(a[i]);
        int n = nums.size();
        int r[n];
        r[n-1] = n;
        for(int i = n-2; i >= 0; i--) {
            if (nums[i+1] > nums[i]) r[i] = i + 1;
            else {
                int j = i + 1;
                while (j != n && nums[j] <= nums[i]) j = r[j];
                r[i] = j;
            }
        }
        for(int i = 0; i < a.size(); i++)
            if (r[i] == n) res.push_back(-1); else res.push_back(nums[r[i]]);
        return res;
    }
};
