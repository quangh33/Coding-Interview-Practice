//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    bool isMajorityElement(vector<int> &nums, int target) {
        int n = nums.size();
        int begin = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        cout << begin << " " << end;
        return (end - begin + 1 > n / 2.0);
    }
};
