//
// Created by Hoang, Quang on 2019-08-25.
//

// https://leetcode.com/problems/h-index/

class Solution {
public:
    int hIndex(vector<int>& a) {
        sort(a.begin(), a.end());
        for(int i = a.size() - 1; i >= 0; i--) {
            int h = a.size() - i;
            if (a[i] >= h && (i == 0 || a[i-1] <= h)) return h;
        }
        return 0;
    }
};