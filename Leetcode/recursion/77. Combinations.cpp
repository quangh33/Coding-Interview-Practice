//
// Created by Hoang, Quang on 2019-08-24.
//

// https://leetcode.com/problems/combinations/


class Solution {
public:
    vector<vector<int>> res;

    void build(int i, int k, vector<int> com, int n, int from) {
        if (i == k) {
            res.push_back(com);
            return;
        }
        for(int j = from; j <= n; j++) {
            com.push_back(j);
            build(i+1, k, com, n, j+1);
            com.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> com = {};
        build(0, k, com, n, 1);
        return res;
    }
};
