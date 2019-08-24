//
// Created by Hoang, Quang on 2019-08-23.
//

// https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<int> a;
    vector<bool> visited;
    vector<vector<int>> res;

    void build(int i, vector<int> nums) {
        int n = nums.size();
        if (i == n) {
            res.push_back(a);
            return;
        }
        for(int j = 0; j < n; j++) {
            if (!visited[j]) {
                visited[j] = true;
                a[i] = nums[j];
                build(i+1, nums);
                visited[j] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        visited = vector<bool>(n, false);
        a = vector<int>(n);

        build(0, nums);
        return res;
    }
};
