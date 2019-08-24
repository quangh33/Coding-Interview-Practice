//
// Created by Hoang, Quang on 2019-08-24.
//

// https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    vector<vector<int>> res;

    void build(vector<int> a, vector<int> subset, int from) {
        res.push_back(subset);
        for(int i = from; i < a.size(); i++) {
            if (i == from || a[i] != a[i-1]) {
                subset.push_back(a[i]);
                build(a, subset, i+1);
                subset.pop_back();
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        sort(a.begin(), a.end());
        vector<int> subset = {};
        build(a, subset, 0);
        return res;
    }
};
