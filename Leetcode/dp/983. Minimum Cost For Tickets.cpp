//
// Created by Hoang, Quang on 2019-08-31.
//
/*
 * prev[i]: the nearest previous travel day
 * fx[i]: total cost to travel from day 1 -> day i
 *
 * prev[i] = go at day i - 1 ? i - 1 : prev[i-1]
 *
 * fx[i] = min(fx[prev[i]] + cost[0],
 *             fx[prev[i-6]] + cost[1],
 *             fx[prev[i-29]] + cost[2])
 *  O(n)
 */
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int n = days.size();
        int prev[366];
        int fx[366];
        bool travel[366];

        memset(travel, 0, sizeof(travel));

        prev[0] = 0;
        for(auto day: days) travel[day] = true;
        for(int i = 1; i <= 365; i++)
            if (travel[i-1]) prev[i] = i-1; else prev[i] = prev[i-1];

        fx[0] = 0;
        for(int i = 0; i < n; i++) {
            int u = days[i];
            fx[u] = INT_MAX;
            fx[u] = min(fx[u], fx[prev[u]] + cost[0]);
            fx[u] = min(fx[u], fx[prev[max(1, u - 6)]] + cost[1]);
            fx[u] = min(fx[u], fx[prev[max(1, u - 29)]] + cost[2]);
        }
        return fx[days[n-1]];
    }
};
