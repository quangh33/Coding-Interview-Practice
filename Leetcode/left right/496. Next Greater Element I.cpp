//
// Created by Hoang, Quang on 2019-08-13.
//
//https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        vector<int> res;
        unordered_map<int, int> index;

        if (m == 0 || n == 0) return res;

        for(int i = 0; i < m; i++) index[b[i]] = i;
        int r[m];
        r[m-1] = -1;
        for(int i = m-2; i >= 0; i--) {
            if (b[i+1] > b[i]) r[i] = i+1;
            else {
                int j = i+1;
                while (j != -1 && b[j] <= b[i]) j = r[j];
                r[i] = j;
            }
        }

        for(int i: a) {
            if (r[index[i]] != -1) res.push_back(b[r[index[i]]]);
            else res.push_back(-1);
        }
        return res;
    }
};

