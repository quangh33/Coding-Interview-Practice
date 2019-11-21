//
// Created by Hoang, Quang on 2019-11-20.
//

class Solution {
public:
    vector<int> a;
    Solution(vector<int>& nums) {
        a = nums;
    }

    int pick(int target) {
        int count = 0;
        int res = -1;

        for(int i = 0; i < a.size(); i++)
            if (a[i] == target) {
                count++;
                int j = rand() % count;
                if (j == 0) res = i;
            }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
