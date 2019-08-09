//
// Created by Hoang, Quang on 2019-08-09.
//

// https://leetcode.com/problems/summary-ranges/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& a) {
        int n = a.size();
        int i = 0;
        vector<string> res;
        if (n == 0) return res;
        while (i < n) {
            int j = i;
            while (j+1 < n && a[j+1] == a[j] + 1) j++;
            if (i != j)
                res.push_back(to_string(a[i]) + "->" + to_string(a[j]));
            else
                res.push_back(to_string(a[i]));

            i = j+1;
        }
        return res;
    }
};

