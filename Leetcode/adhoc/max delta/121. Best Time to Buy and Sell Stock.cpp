class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() ==0) return 0;
        int minSoFar = prices[0];
        int maxProfit = 0;
        for(int p: prices) {
            maxProfit = max(maxProfit, p - minSoFar);
            minSoFar = min(minSoFar, p);
        }
        return maxProfit;
    }
};