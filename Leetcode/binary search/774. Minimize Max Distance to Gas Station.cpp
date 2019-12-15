//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    double eps = 0.000001;

    bool ok(double mid, vector<int> a, int k) {
        int count = 0;
        int n = a.size();
        for (int i = 0; i < n - 1; i++) {
            double dis = 1.0 * (a[i + 1] - a[i]);
            if (dis <= mid) continue;
            double x = dis / mid;
            if (x == int(x)) {
                count = count + x - 1;
            } else {
                count = count + int(x);
            }
            if (count > k) return false;
        }
        return count <= k;
    }

    double minmaxGasDist(vector<int> &a, int K) {
        double low = 0, high = 0;
        int n = a.size();
        sort(a.begin(), a.end());
        for (int i = 0; i < n - 1; i++)
            high = max(high, 1.0 * (a[i + 1] - a[i]));

        double res;
        while (low + eps <= high) {
            double mid = (high + low) / 2.0;
            if (ok(mid, a, K)) {
                res = mid;
                high = mid;
            } else low = mid;
        }
        return res;
    }
};