//
// Created by Hoang, Quang on 2019-08-15.
//

// https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& a) {
        int n = a.size();
        int fx[n+1];
        fx[0] = 0;
        fx[1] = 0;
        for(int i = 2; i <= n; i++) {
            fx[i] = min(fx[i-1] + a[i-1], fx[i-2] + a[i-2]);
        }
        return fx[n];
    }
};
