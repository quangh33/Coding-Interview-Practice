//
// Created by Hoang, Quang on 2019-08-09.
//

//  https://leetcode.com/problems/intersection-of-two-arrays/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int i = 0, j = 0;
        vector<int> res;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                res.push_back(a[i]);
                while (i+1 < a.size() && a[i+1] == a[i]) i++;
                i++;
                while (j+1 < b.size() && b[j+1] == b[j]) j++;
                j++;
            } else {
                if (a[i] < b[j]) i++;
                else j++;
            }
        }
        return res;
    }
};