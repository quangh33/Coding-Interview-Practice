//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    vector <string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        int n = nums.size();
        long long cover = lower - 1L;
        int i = 0;
        vector <string> res;
        while (i < n) {
            if (nums[i] - 1L > cover) {
                if (cover + 2L == nums[i])
                    res.push_back(to_string(cover + 1L));
                else
                    res.push_back(to_string(cover + 1L) + "->" + to_string(nums[i] - 1L));
            }
            cover = nums[i];
            i++;
        }
        if (cover < upper) {
            if (cover + 1L == upper)
                res.push_back(to_string(cover + 1L));
            else
                res.push_back(to_string(cover + 1) + "->" + to_string(upper));
        }
        return res;
    }
};
