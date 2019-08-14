//
// Created by Hoang, Quang on 2019-08-14.
//

// https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& a) {
        int n = a.size();
        int sum = 0;
        for (int i = 0; i < n; i++) sum+=a[i];
        return (n+1)*n/2 - sum;
    }
};