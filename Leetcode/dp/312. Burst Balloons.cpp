//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int fx[n][n];
        memset(fx, 0, sizeof(fx));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                for (int k = i; k <= j; k++) {
                    int left = 0, right = 0;
                    if (k > i) left = fx[i][k - 1];
                    if (k < j) right = fx[k + 1][j];

                    int before = 1, after = 1;
                    if (i > 0) before = nums[i - 1];
                    if (j < n - 1) after = nums[j + 1];

                    fx[i][j] = max(fx[i][j], left + right + before * after * nums[k]);
                }
            }
        }

        return fx[0][n - 1];
    }
};