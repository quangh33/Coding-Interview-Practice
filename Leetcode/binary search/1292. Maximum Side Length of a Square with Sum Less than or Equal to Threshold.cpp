//
// Created by Hoang, Quang on 2019-12-19.
//

class Solution {
    int n, m;
    int s[301][301];
    // check if there is a matrix mid * mid that sum <= k
    bool ok(int mid, int k) {
        for(int i = mid; i <= n; i++)
            for(int j = mid; j <= m; j++) {
                int u = i - mid + 1;
                int v = j - mid + 1;
                int sum = s[i][j] - s[u-1][j] - s[i][v-1] + s[u-1][v-1];
                if (sum <= k) return true;
            }

        return false;
    }

public:
    int maxSideLength(vector<vector<int>>& a, int k) {
        n = a.size();
        m = a[0].size();
        memset(s, 0, sizeof(s));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                s[i][j] = s[i-1][j] + s[i][j-1] + a[i-1][j-1] - s[i-1][j-1];

        int low = 1, high = min(n, m);
        int res = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (ok(mid, k)) {
                res = max(res, mid);
                low = mid + 1;
            } else high = mid - 1;
        }

        return res;
    }
};
