//
// Created by Hoang, Quang on 2019-09-05.
//

// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int n = a.size();
        int i = 0, j = n-1;
        while (i < j) {
            int sum = a[i] + a[j];
            if (sum <= target) {
                if (sum == target) {
                    vector<int> res = { i+1, j+1 };
                    return res;
                }
                i++;
            } else j--;
        }
        return vector<int>();
    }
};