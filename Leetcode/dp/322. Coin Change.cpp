//
// Created by Hoang, Quang on 2019-08-31.
//

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int fx[amount+1];

        fx[0] = 0;
        for(int i = 1; i <= amount; i++) {
            fx[i] = INT_MAX;
            for(int j = 0; j < n; j++)
                if (coins[j] <= i) {
                    if (fx[i-coins[j]] != INT_MAX)
                        fx[i] = min(fx[i], fx[i-coins[j]] + 1);
                }
        }
        return fx[amount] == INT_MAX ? -1 : fx[amount];
    }
};
