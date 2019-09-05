//
// Created by Hoang, Quang on 2019-09-05.
//

class Solution {
public:
    int threeSumClosest(vector<int>& a, int target) {
        int n = a.size();
        sort(a.begin(), a.end());
        int minDelta = INT_MAX;
        int res;

        for(int i = 0; i < n - 2; i++) {
            int delta = target - a[i];

            int l = i + 1;
            int r = n - 1;
            int sum;
            int s = INT_MAX;
            while (l < r) {
                sum = a[l] + a[r];
                if (sum >= delta) {
                    s = min(s, sum);
                    r--;
                } else l++;
            }
            if (s != INT_MAX) {
                if (abs(s + a[i] - target) < minDelta) {
                    minDelta = s + a[i] - target;
                    res = s + a[i];
                }
            }

            l = i + 1;
            r = n - 1;

            s = INT_MIN;
            while (l < r) {
                sum = a[l] + a[r];
                if (sum <= delta) {
                    s = max(s, sum);
                    l++;
                } else r--;
            }

            if (s != INT_MIN) {
                if (abs(s + a[i] - target) < minDelta) {
                    minDelta = abs(s + a[i] - target);
                    res = s + a[i];
                }
            }
        }

        return res;
    }
};