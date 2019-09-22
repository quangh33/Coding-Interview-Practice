//
// Created by Hoang, Quang on 2019-08-26.
//

// https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestOnes(vector<int>& a, int K) {
        int n = a.size();
        int i = 0, j = 0, res = 0;
        int num = a[i] == 0 ? 1 : 0;
        while (i < n) {
            if (num <= K) {
                res = max(res, i - j + 1);
                i++;
                if (i < n) num += (a[i] == 0);
            } else {
                num -= (a[j] == 0);
                j++;
            }
        }
        return res;
    }
};