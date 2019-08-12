//
// Created by Hoang, Quang on 2019-08-12.
//

// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n = a.size();
        if (n == 0) return 0;
        int l[n], r[n];
        l[0] = -1;
        for(int i = 1; i < n; i++) {
            if (a[i-1] < a[i]) l[i] = i-1;
            else {
                int j = i-1;
                while (j != -1 && a[j] >= a[i]) j = l[j];
                l[i] = j;
            }
        }

        r[n-1] = n;
        for(int i = n-2; i >= 0; i--) {
            if (a[i+1] < a[i]) r[i] = i+1;
            else {
                int j = i+1;
                while (j != n && a[j] >= a[i]) j = r[j];
                r[i] = j;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, a[i] * (r[i]-l[i]-1));
        }
        return res;
    }
};
