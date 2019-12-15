//
// Created by Hoang, Quang on 2019-08-09.
//

#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &a) {
        int n = a.size();
        for (int i = 1; i < n; i++) a[i] = a[i] + a[i - 1];
        int currentMin = 0;
        int res = a[0];
        for (int i = 0; i < n; i++) {
            res = max(res, a[i] - currentMin);
            currentMin = min(currentMin, a[i]);
        }
        return res;
    }
};