//
// Created by Hoang, Quang on 2019-09-02.
//

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public:
    int maxProfit(vector<int>& a, int fee) {
        int n = a.size();
        if (n == 0) return 0;
        int buy[n], sell[n];
        buy[0] = - a[0] - fee;
        sell[0] = 0;
        for(int i = 1; i < n; i++) {
            buy[i] = max(buy[i-1], sell[i-1] - a[i] - fee);
            sell[i] = max(sell[i-1], buy[i-1] + a[i]);
        }
        return sell[n-1];
    }
};