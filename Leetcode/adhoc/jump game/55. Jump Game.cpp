//
// Created by Hoang, Quang on 2019-08-24.
//

// https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& a) {
        int n = a.size();
        int farest = 0;
        for(int i = 0; i < n; i++) {
            if (i > farest) break;
            farest = max(farest, i + a[i]);
        }
        return farest >= n-1;
    }
};