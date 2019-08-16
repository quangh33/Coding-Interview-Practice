//
// Created by Hoang, Quang on 2019-08-16.
//

https://leetcode.com/problems/third-maximum-number/

class Solution {
public:
    int thirdMax(vector<int>& a) {
        int n = a.size();
        int max1 = a[0];
        long long max2 = LLONG_MIN, max3 = LLONG_MIN;

        for(int i = 1; i < n; i++) {
            if (a[i] == max1 || a[i] == max2 || a[i] == max3) continue;
            if (a[i] > max1) {
                max3 = max2;
                max2 = max1;
                max1 = a[i];
            } else if (a[i] > max2) {
                max3 = max2;
                max2 = a[i];
            } else if (a[i] > max3) {
                max3 = a[i];
            }
        }
        return max3 == LLONG_MIN ? max1 : max3;
    }
};

