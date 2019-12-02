//
// Created by Hoang, Quang on 2019-08-09.
//
// https://leetcode.com/problems/degree-of-an-array/

#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& a) {
        int n = a.size();
        if (n == 0) return 0;
        int count[50000], first[50000], last[50000];
        int res = n;
        memset(count, 0, sizeof(count));
        memset(first, -1, sizeof(first));
        memset(last, -1, sizeof(last));

        int degree = 0;
        for(int i = 0; i < n; i++) {
            count[a[i]]++;
            if (first[a[i]] == -1) first[a[i]] = i;
            last[a[i]] = i;
            degree = max(degree, count[a[i]]);
        }

        for(int i: a) {
            if (degree == count[i]) {
                res = min(res, last[i] - first[i] + 1);
            }
        }
        return res;
    }
};