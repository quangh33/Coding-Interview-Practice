//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    int validSubarrays(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int r[n];
        r[n - 1] = n;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i + 1] < nums[i]) r[i] = i + 1;
            else {
                int j = i + 1;
                while (j != n && nums[j] >= nums[i]) j = r[j];
                r[i] = j;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) res += (r[i] - i);
        return res;
    }
};
