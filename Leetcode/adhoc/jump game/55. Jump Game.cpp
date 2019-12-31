//
// Created by Hoang, Quang on 2019-08-24.
//

// https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& a) {
        int n = a.size();
        int furthest = 0;
        for(int i = 0; i <= furthest; i++) {
            if (furthest >= n-1) return true;
            furthest = max(furthest, i + a[i]);
        }
        return false;
    }
};