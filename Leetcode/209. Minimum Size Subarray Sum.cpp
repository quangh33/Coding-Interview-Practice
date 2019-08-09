//
// Created by Hoang, Quang on 2019-08-09.
//

// https://leetcode.com/problems/minimum-size-subarray-sum/


#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& a) {
        int n = a.size();
        if (n == 0) return 0;
        int res = n+1;
        int i = 0;
        int j = 0;
        int sum = a[0];
        while (i < n && j < n) {
            if (sum >= s) {
                res = min(res, j-i+1);
                sum-=a[i];
                i++;
            } else {
                j++;
                if (j < n) sum+=a[j];
            }
        }
        return res == n+1 ? 0 : res;
    }
};
