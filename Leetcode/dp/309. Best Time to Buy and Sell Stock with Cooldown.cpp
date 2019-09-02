//
// Created by Hoang, Quang on 2019-09-01.
//

/*
 * buy[i]: max profit until day i and the last action is buying
 * sell[i]: max profit until day i and the last action is selling
 *
 * buy[i] = max(buy[i-1], // do not buy on day i
 *              sell[i-2] - a[i] // buy on day i => must sell on /before day i-2)
 *
 * sell[i] = max(sell[i-1], // do not sell on day i
 *               buy[i-1] + a[i] // sell on day i
 *
 * res = sell[n-1];
 *
 * O(n);
 */
class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        if (n == 0) return 0;
        int buy[n], sell[n];
        buy[0] = -a[0];
        sell[0] = 0;
        for(int i = 1; i < n; i++) {
            buy[i] = max(buy[i-1], i > 1 ? sell[i-2] - a[i] : -a[i]);
            sell[i] = max(sell[i-1], buy[i-1] + a[i]);
        }
        return sell[n-1];
    }
};