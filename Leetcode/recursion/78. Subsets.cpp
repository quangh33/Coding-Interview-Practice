//
// Created by Hoang, Quang on 2019-08-24.
//

// https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> res;
        for(int i = 0; i < (1 << n); i++) {
            vector<int> subset;
            for(int j = 0; j < n; j++)
                if (i & (1 << j)) subset.push_back(a[j]);
            res.push_back(subset);
        }
        return res;
    }
};

class Solution_Recursion {
public:
    vector<vector<int>> res;
    void build(vector<int> a, vector<int> subset, int from) {
        res.push_back(subset);
        for(int i = from; i < a.size(); i++) {
            subset.push_back(a[i]);
            build(a, subset, i+1);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& a) {
        vector<int> subset = {};
        build(a, subset, 0);
        return res;
    }
};
