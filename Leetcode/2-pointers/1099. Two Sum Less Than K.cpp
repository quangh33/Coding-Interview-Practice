//
// Created by Hoang, Quang on 2019-09-05.
//

class Solution {
public:
    int twoSumLessThanK(vector<int>& a, int K) {
        sort(a.begin(), a.end());
        int n = a.size();
        int i = 0;
        int j = n-1;
        int res = INT_MIN;
        while (i < j) {
            int sum = a[i] + a[j];
            if (sum < K) {
                res = max(res, sum);
                i++;
            } else j--;
        }
        if (res == INT_MIN) return -1;
        else return res;
    }
};