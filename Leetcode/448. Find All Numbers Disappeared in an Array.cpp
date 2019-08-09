//
// Created by Hoang, Quang on 2019-08-09.
//

// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& a) {
        int n = a.size();
        for(int i = 0; i < n; i++) {
            int index = abs(a[i]) - 1;
            if (a[index] > 0) a[index] = -a[index];
        }
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if (a[i] > 0) res.push_back(i+1);
        }
        return res;
    }
};

