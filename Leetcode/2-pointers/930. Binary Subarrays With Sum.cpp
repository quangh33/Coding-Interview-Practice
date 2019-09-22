//
// Created by Hoang, Quang on 2019-09-22.
//

// https://leetcode.com/problems/binary-subarrays-with-sum/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int, int> count;
        count[0] = 1;
        int s = 0;
        int res = 0;
        for(int i: A) {
            s+=i;
            res = res + count[s-S];
            count[s]++;
        }
        return res;
    }
};
