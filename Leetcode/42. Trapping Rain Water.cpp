//
// Created by Hoang, Quang on 2019-08-09.
//

// https://leetcode.com/problems/trapping-rain-water/


#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        if (n == 0) return 0;
        int l[n], r[n];
        r[n-1] = n-1;
        l[0] = 0;

        for(int i = 1; i < n; i++) {
            if (a[i-1] >= a[i]) l[i] = l[i-1];
            else {
                int j = i-1;
                while (j != l[j] && a[j] < a[i]) j = l[j];
                if (a[j] > a[i]) l[i] = j; else l[i] = i;
            }
        }

        for(int i = n-2; i >= 0; i--) {
            if (a[i+1] >= a[i]) r[i] = r[i+1];
            else {
                int j = i+1;
                while (j != r[j] && a[j] < a[i]) j = r[j];
                if (a[j] > a[i]) r[i] = j; else r[i] = i;
            }
        }

        int res = 0;
        for(int i = 0; i < n; i++) res+= min(a[l[i]] - a[i], a[r[i]] - a[i]);
        return res;
    }
};

